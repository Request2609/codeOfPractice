#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <sys/eventfd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include  <unistd.h>    
#include  <sys/types.h>  
#include  <sys/socket.h>  
#include  <sys/ioctl.h>  
#include  <netinet/in.h>  
#include <netinet/tcp.h>
#include  <arpa/inet.h>  
#include  <netdb.h>  


#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <sys/epoll.h>
#include <fcntl.h>


//使用epoll实现多路复用


//将文件描述符设置为非阻塞
void SetNoBlock(int fd)
{
  int flag =  fcntl(fd,F_GETFL);
  fcntl(fd,F_SETFL, flag | O_NONBLOCK);
}

int open_listenfd(char *port) {
    struct addrinfo hints, *listp, *p;
    int listenfd = 0, optval = 1;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG; // 被动的  任何IP address
    hints.ai_flags |= AI_NUMERICSERV; // use port number
    getaddrinfo(NULL, port, &hints, &listp);
    
    for (p = listp; p ; p = p->ai_next) {
        if ((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
            continue;
        }
        
        setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
        
        if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0) {
            break;//Success
        }
        close(listenfd);
    }
    
    freeaddrinfo(listp);
    if (!p) {
        return -1;
    }
    if (listen(listenfd, 30) < 0) {
        close(listenfd);
        return -1;
    }
    return listenfd;
}

void setW(int epfd, int fd) {
    epoll_event event1 ;
    event1.data.fd = fd ;
    event1.events = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &event1) ;
}

void add(int epfd, int fd) {
    epoll_event event ;
    event.data.fd = fd ;
    event.events = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event) ;
}

void writefd(int fd, int64_t t){
    write(fd, &t, sizeof(t)) ;
}

//主函数
int main(int argc,char * argv[])
{
    int listenfd ;
    //listenfd = open_listenfd("8888");
    
    //1.创建epoll对象
    int epfd = epoll_create(256);
    if(epfd < 0)
    {
        perror("epoll_create");
        return 3;
    }
    int socket_pair[2] ;
    if(socketpair(AF_UNIX, SOCK_STREAM, 0, socket_pair) == -1 ) {
        printf("Error, socketpair create failed, errno(%d): %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }
    add(epfd, socket_pair[1]) ;
    add(epfd, socket_pair[0]) ;
    const char* buf = "helloworld!" ;
    std::cout << "写数据，fd－－－－－>" << socket_pair[1] << std::endl;
    write(socket_pair[1], buf, strlen(buf)) ;
 /*   int fd = eventfd(10, 0) ;
    add(epfd, fd) ;
    std::cout << "写数据" << std::endl ;
    writefd(fd, 4);*/
    while(true)
    {
        //创建事件数组，返回已经就绪的文件
        epoll_event events[2];
        int size = epoll_wait(epfd,events,sizeof(events)/sizeof(events[0]),-1);
        if(size < 0)
        {
            perror("epoll_wait");
            continue;
        }
        if(size == 0)
        {
            printf("time out\n");
            continue;
        }
        int i = 0;
        for(i = 0; i < size ;++i)
        {
            int fd = events[i].data.fd ;
            if(fd == listenfd) {
                int connfd = 0 ;
                if((connfd=accept(listenfd, NULL, NULL)) < 0) {
                    std::cout << "----------出错" << std::endl ;
                }
                SetNoBlock(connfd) ;
                add(epfd, connfd) ;
                continue ;
            }

            if(events[i].events&EPOLLOUT) {
                std::cout << "可写事件，写数据----->"<<fd << std::endl ;
                const char* buf = "hello world!" ;
                write(fd, buf, strlen(buf)) ;         
            }

            //触发可读事件
            if(events[i].events&EPOLLIN) {
                char buf[1024] ;
                read(fd, buf, sizeof(buf))  ;             
                std::cout << "读取--->fd" << fd << std::endl ;
                ///注册可写事件
                setW(epfd, fd) ;
            }
        }
    }
    close(epfd);
}

