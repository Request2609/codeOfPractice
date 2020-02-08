#include "aeEpoll.h"

int aeEpoll :: add(int fd, int events) {
    
    struct epoll_event ev ;
    ev.data.fd = fd ;
    ev.events = events ;
    if(epoll_ctl(epFd, EPOLL_CTL_ADD, fd, &ev) < 0) {
        cout << __FILE__ << "         " << __LINE__ << endl ;
        return -1 ;
    }
    return 1 ;
}

int aeEpoll :: epCreate(int size) {
    epFd = epoll_create(size) ;
    if(epFd < 0) {
        return -1 ;
    }
    //预先扩展数组
    eventFds.reserve(nfds) ;
    return epFd ;
}

int aeEpoll :: modify(int fd, int event) {
    struct epoll_event ev ;
    //设置套接字
    ev.data.fd = fd ;
    //设置事件监听类型
    ev.events = event ;
    if(epoll_ctl(epFd, EPOLL_CTL_MOD, fd, &ev) < 0) {
        cout << __FILE__ << "      "<< __LINE__ << endl ;
        return -1 ;
    }
    return 1 ;
}

int aeEpoll :: del(int fd) {
    if(epoll_ctl(epFd, EPOLL_CTL_DEL, fd, NULL) < 0) {
        cout <<  __FILE__ << "       " << __LINE__ << endl ;
        return -1 ;
    }
    return 1 ;
}

//将所有活跃事件收起来ls
int aeEpoll :: wait(vector<epoll_event>&ls) {
    int eventNum = epoll_wait(epFd, &eventFds[0], eventFds.capacity(), -1) ;
    if(eventNum < 0 && errno != EINTR) {
        cout << errno << "     " << strerror(errno) << "      " << __FILE__ << "         " << __LINE__ <<  endl ;
        return -1 ;
    }
    else {
        for(int i=0; i < eventNum; i++) {
            ls.push_back(eventFds[i]) ;
        }
    }
    return eventNum ;
}

