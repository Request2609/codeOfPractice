#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <stdio.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#define MAX_EVENTS  1024
#define BUFLEN 128
#define SERV_PORT   8080


/*
 * status:1表示在监听事件中，0表示不在 
 * last_active:记录最后一次响应时间,做超时处理
 */
struct myevent_s 
{
    int fd;                 //cfd listenfd
    int events;             //EPOLLIN  EPLLOUT
    void *arg;              //指向自己结构体指针
    void (*call_back)(int fd, int events, void *arg);
    int status;
    char buf[BUFLEN];
    int len;
    long last_active;
};

int g_efd;          /* epoll_create返回的句柄 */
struct myevent_s g_events[MAX_EVENTS+1];   /* +1 最后一个用于 listen fd */

/*
struct epoll_event 
结构体epoll_event被用于注册所感兴趣的事件和回传所发生待处理的事件，定义如下：

struct epoll_event 
{
    __uint32_t events;       epoll event 
    epoll_data_t data;       User data variable 
};
typedef union epoll_data 
{
    void *ptr;
    int fd;
    __uint32_t u32;
    __uint64_t u64;
} epoll_data_t; //保存触发事件的某个文件描述符相关的数据
*/

//初始化myevent_s类型
void eventset(struct myevent_s* ev, int fd, void (*call_back)(int, int, void *), void* arg)
{
    ev->fd = fd;
    ev->call_back = call_back;
    ev->events = 0;
    ev->arg = arg;
    ev->status = 0;
    // memset(ev->buf, 0, sizeof(ev->buf));  本模型将收到的数据再发回去，所以不memset
    // ev->len = 0;  这个成员表示recv的数据长度，但是在逻辑里也没用到
    //而且加上这一句在我的测试中只要客户端发送两条数据之后就会被close fd
    //没明白为什么...可能这就是传说中的那种接手后发现代码里有一段
    //留下来的注释：“我也不知道这段代码有什么用，但是没有就会bug”的代码
    ev->last_active = time(NULL);

    return;
}

void recvdata(int fd, int events, void *arg);
void senddata(int fd, int events, void *arg);

//将fd添加到epoll注册的事件合集
void eventadd(int efd, int events, struct myevent_s *ev)
{
    struct epoll_event epv = {0, {0}};
    int op;
    epv.data.ptr = ev;
    epv.events = ev->events = events;

    if (ev->status == 1) 
    {
        op = EPOLL_CTL_MOD;
    } 
    else 
    {
        op = EPOLL_CTL_ADD;
        ev->status = 1;
    }

    if (epoll_ctl(efd, op, ev->fd, &epv) < 0)
        printf("event add failed [fd=%d], events[%d]\n", ev->fd, events);
    else
        printf("event add OK [fd=%d], op=%d, events[%0X]\n", ev->fd, op, events);

    return;
}

//从事件合集中删除
void eventdel(int efd, struct myevent_s *ev) {
    struct epoll_event epv = {0, {0}};

    if (ev->status != 1)
    {
        return ;
    }

    epv.data.ptr = ev;
    ev->status = 0;
    epoll_ctl(efd, EPOLL_CTL_DEL, ev->fd, &epv);

    return;
}


//当有新的连接时，调用监听listenfd的此回调函数，指定新sockfd的回调函数
void acceptconn(int lfd, int events, void *arg)
{
    printf("****************************\n");
    struct sockaddr_in cin;
    socklen_t len = sizeof(cin);
    int cfd, i;

    if ((cfd = accept(lfd, (struct sockaddr *)&cin, &len)) == -1) 
    {
        if (errno != EAGAIN && errno != EINTR) 
        {
            /* 暂时不做出错处理 */
        }
        printf("%s: accept, %s\n", __func__, strerror(errno));
        return;
    }

    do {
        for (i = 0; i < MAX_EVENTS; i++) 
        {
            if (g_events[i].status == 0)
            {
                break;
            }
        }

        if (i == MAX_EVENTS) 
        {
            printf("%s: max connect limit[%d]\n", __func__, MAX_EVENTS);
            break;
        }

        int flag = 0;
        if ((flag = fcntl(cfd, F_SETFL, O_NONBLOCK)) < 0)
        {
            printf("%s: fcntl nonblocking failed, %s\n", __func__, strerror(errno));
            break;
        }

        eventset(&g_events[i], cfd, recvdata, &g_events[i]);
        eventadd(g_efd, EPOLLIN, &g_events[i]);
    } while(0);

    printf("new connect [%s:%d][time:%ld], pos[%d]\n", inet_ntoa(cin.sin_addr), ntohs(cin.sin_port), g_events[i].last_active, i);

    return;
}

void recvdata(int fd, int events, void *arg)
{
    struct myevent_s *ev = (struct myevent_s *)arg;
    int len;

    len = recv(fd, ev->buf, sizeof(ev->buf), 0);
    eventdel(g_efd, ev);    //接受完数据 删除该监听事件

    if (len > 0) 
    {
        ev->len = len;
        ev->buf[len] = '\0';
        printf("C[%d]:%s\n", fd, ev->buf);
        /* 转换为发送事件 */
        eventset(ev, fd, senddata, ev);
        eventadd(g_efd, EPOLLOUT, ev); //再把其添加到监听事件中,此时回调函数改为了senddata
        //将socket事件修改为EPOLLOUT用于服务器发送消息给客户端
    }
    else if (len == 0) 
    {
        close(ev->fd);
        /* ev-g_events 地址相减得到偏移元素位置 */
        printf("[fd=%d] pos[%d], closed\n", fd, (int)(ev - g_events));
    }
    else 
    {
        close(ev->fd);
        printf("recv[fd=%d] error[%d]:%s\n", fd, errno, strerror(errno));
    }

    return;
}

void senddata(int fd, int events, void *arg)
{
    struct myevent_s *ev = (struct myevent_s *)arg;
    int len;

    len = send(fd, ev->buf, ev->len, 0);
    printf("fd=%d\tev->buf=%s\ttev->len=%d\n", fd, ev->buf, ev->len);
    printf("send len = %d\n", len);

    eventdel(g_efd, ev); //删除该事件
    if (len > 0) 
    {
        printf("send[fd=%d], [%d]%s\n", fd, len, ev->buf);
        eventset(ev, fd, recvdata, ev);
        eventadd(g_efd, EPOLLIN, ev);   //添加该事件，已更改回调函数为recvdata
        //修改socket事件为EPOLLIN用于接收客户端发来的消息
    }
    else 
    {
        close(ev->fd);
        printf("send[fd=%d] error %s\n", fd, strerror(errno));
    }

    return;
}

//初始化一个sockfd
void initlistensocket(int efd, short port)
{
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    fcntl(lfd, F_SETFL, O_NONBLOCK);
    eventset(&g_events[MAX_EVENTS], lfd, acceptconn, &g_events[MAX_EVENTS]);
    eventadd(efd, EPOLLIN, &g_events[MAX_EVENTS]);

    struct sockaddr_in sin;

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);

    bind(lfd, (struct sockaddr *)&sin, sizeof(sin));

    listen(lfd, 20);

    return;
}

int main(int argc, char *argv[])
{
    unsigned short port = SERV_PORT;

    if (argc == 2)
        port = atoi(argv[1]);

    g_efd = epoll_create(MAX_EVENTS+1);

    if (g_efd <= 0)
        printf("create efd in %s err %s\n", __func__, strerror(errno));

    initlistensocket(g_efd, port);

    /* 事件循环 */
    struct epoll_event events[MAX_EVENTS+1];
    printf("server running:port[%d]\n", port);
    int checkpos = 0, i;
    while (1) 
    {
        /* 超时验证，每次测试100个链接，不测试listenfd 当客户端60秒内没有和服务器通信，则关闭此客户端链接 */
        long now = time(NULL);
        for (i = 0; i < 100; i++, checkpos++) 
        {
            if (checkpos == MAX_EVENTS)
            {
                checkpos = 0;
            }
            if (g_events[checkpos].status != 1)
            {
                continue;
            }
            long duration = now - g_events[checkpos].last_active;
            if (duration >= 60) 
            {
                close(g_events[checkpos].fd);
                printf("[fd=%d] timeout\n", g_events[checkpos].fd);
                eventdel(g_efd, &g_events[checkpos]);
            }
        }
        /* 等待事件发生 */
        int nfd = epoll_wait(g_efd, events, MAX_EVENTS+1, 1000);
        if (nfd < 0) 
        {
            printf("epoll_wait error, exit\n");
            break;
        }

        for (i = 0; i < nfd; i++) 
        {
            struct myevent_s *ev = (struct myevent_s *)events[i].data.ptr;
            if ((events[i].events & EPOLLIN) && (ev->events & EPOLLIN)) 
            {
                //可读
                ev->call_back(ev->fd, events[i].events, ev->arg);
            }
            if ((events[i].events & EPOLLOUT) && (ev->events & EPOLLOUT)) 
            {
                //可写
                ev->call_back(ev->fd, events[i].events, ev->arg);
            }
        }
    }

    /* 退出前释放所有资源 */
    return 0;
}
