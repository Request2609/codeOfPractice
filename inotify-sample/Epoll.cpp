#include "Epoll.h"

void epOperation :: add(int fd, int events) {
    struct epoll_event ev ;
    ev.data.fd = fd ;
    ev.events = events ;
    if(epoll_ctl(epFd, EPOLL_CTL_ADD, fd, &ev) < 0) {
        std :: cout << __FILE__ << "   " << __LINE__ << "   " << strerror(errno)<< std :: endl ;
        return ;
    }
    
    if(++ fds > nfds) {
        nfds *= 2 ;
        epFds.reserve(nfds) ;
    }
}

//修改事件监听类型
void epOperation :: change(int fd, int events) {
    struct epoll_event ev ;
    ev.data.fd = fd ;
    ev.events = events ;
    if(epoll_ctl(epFd, EPOLL_CTL_MOD, fd, &ev) < 0) {
        std :: cout << __FILE__ << "   " << __LINE__ << std :: endl ;
        return ;
    }
}

void epOperation :: del(int fd) {
    if(epoll_ctl(epFd, EPOLL_CTL_DEL, fd, NULL) < 0){
 //       std :: cout << __FILE__ << "   " << __LINE__ << "      " << strerror(errno)<< std :: endl ;
        return  ;
    }
    fds -- ;
}

void epOperation :: del(int epFd, int fd) {
    if(epoll_ctl(epFd, EPOLL_CTL_DEL, fd, NULL) < 0){
   //     std :: cout << __FILE__ << "   " << __LINE__ << std :: endl ;
        return  ;
    }
}

//将活跃的事件全加入到clList
int epOperation :: wait(int64_t timeout, vector<int>&fdList) {
    int eventNum ;
    //struct epoll_event epFd_[200] ;
    try{ 
        eventNum = epoll_wait(epFd, &(*epFds.begin()), 200, timeout) ;
    }catch(exception e) {
        cout << e.what() ;
    }
    if(eventNum < 0) {
        cout << eventNum << "           错误：" << strerror(errno) << endl ;
        return -1 ;
    }
    
    for(int i=0; i<eventNum; i++) {
        //只接受可读事件
        if(epFds[i].events&POLLIN) {
            fdList.push_back(epFds[i].data.fd) ;
        }
        if(epFds[i].events& EPOLLERR) {
            cout << "发生了错误EPOLL" << endl ;
        }
    }
    epFds.clear() ;
    //将活跃的事件全部加入到事件列表中
        //要是还未注册的事件
    return eventNum ;
}

