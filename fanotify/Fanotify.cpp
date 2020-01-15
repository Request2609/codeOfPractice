#include <iostream>
#include "Fanotify.h"

Fanotify :: Fanotify() {
    fMask = FAN_OPEN|FAN_CLOSE|FAN_ACCESS|FAN_MODIFY ;
    markFlag = FAN_MARK_ADD ;
}

Fanotify :: ~Fanotify() {
    close(fanFd) ;
}
//设置监控对象为目录下的子文件
void Fanotify::setNotifyObject(std::string path) {
    fanMask |= FAN_EVENT_ON_CHILD  ;  
    initFlag|=FAN_CLASS_NOTIF ;
    initFlag = 0 ;
    fanFd = fanotify_init(initFlag, O_RDONLY) ;
    if(fanFd < 0) {
        std :: cout << __FILE__ << "   " << __LINE__ << std :: endl ;
        return ;
    }
    makeObject(path.c_str()) ;
}

//设置监控的对象
int Fanotify:: makeObject(const std:: string paths) {
       return fanotify_mark(fanFd, markFlag, AT_FDCWD, fanMask, paths.c_str()) ;
}

int Fanotify :: getNotifyFD() {
    return fanFd ;
}

void Fanotify:: startListen() {
    char buf[4096];
    int len = 0 ;
    selectEvent() ;
    while((len = read(fanFd, buf, sizeof(buf))) < 0) {
        struct fanotify_event_metadata* metadata ;
        char path[PATH_MAX] ;
        int pathLen ;
        metadata = (fanotify_event_metadata*)buf ;
        while(FAN_EVENT_OK(metadata, len)) {
            if(metadata->vers < 2) {
                fprintf(stderr, "kernel fanotify version too old!\n") ;
                exit(1);
            }
            if(metadata->fd >= 0) {
                sprintf(path, "/proc/self/fd/%d", metadata->fd) ;
                pathLen = readlink(path, path, sizeof(path)-1) ;
                if(pathLen < 0) {
                    exit(1) ;
                }
                path[pathLen] = '\0' ;
            }
            std::cout << "发生事件的进程ID:"<< metadata->pid << std::endl ;
            int flag = getEvent(metadata) ;   
            selectEvent() ;
        }
    }
}

int Fanotify:: selectEvent() {
    fd_set rfd ;
    //使用select监听
    FD_ZERO(&rfd) ;
    FD_SET(fanFd, &rfd) ;
    while(select(fanFd+1, & rfd, NULL, NULL, NULL) < 0) {
        if(errno != EINTR) {
            exit(0) ;
        }
    }
    return 1 ;
}

int Fanotify::getEvent(const struct fanotify_event_metadata* metadata) {
    char buf[4096] ;
    std::string paths ;
    while(FAN_EVENT_OK(metadata, len)) {
        //处理matadata
        if(metadata->mask&FAN_OPEN) {
            std :: cout << "文件被打开" << std:: endl ;
            return OPEN ;
        }   
        if(metadata->mask&FAN_CLOSE) {
            if(metadata->mask&FAN_CLOSE_WRITE) {
                std:: cout << "write(writeble)" << std:: endl  ;
                return CLOSE_MODIFY ;
            }   
            if(metadata->mask&FAN_CLOSE_NOWRITE) {
                std :: cout << "close" <<std:: endl ;
                return CLOSE ;
            }
        }
        if(metadata->mask&FAN_MODIFY){
            std::cout << "修改" << std :: endl ;
            return MODIFY;
        }
        if(metadata->fd >= 0 && close(metadata->fd) != 0) exit(1) ;
        metadata = FAN_EVENT_NEXT(metadata, len) ;
    }   
    return 1 ;
}   

