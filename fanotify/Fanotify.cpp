#include <iostream>
#include "Fanotify.h"

Fanotify :: Fanotify() {
    fMask = FAN_OPEN|FAN_CLOSE|FAN_ACCESS|FAN_MODIFY ;
    markFlag = FAN_MARK_ADD ;
}

Fanotify :: ~Fanotify() {
    close(fd) ;
}
//设置监控对象为目录下的子文件
void Fanotify::setNotifyObject() {
    fanMask |= FAN_EVENT_ON_CHILD  ;  
    initFlag|=FAN_CLASS_NOTIF ;
    fd = fanotify_init(initFlag, O_RDONLY) ;
    if(fd < 0) {
        std :: cout << __FILE__ << "   " << __LINE__ << std :: endl ;
        return ;
    }
}

//设置监控的对象
int Fanotify:: makeObject(int dstFd, const std:: string paths, 
                  uint64_t mask, unsigned int flags) {
       return fanotify_mark(fd, flags, mask, dstFd, paths.c_str()) ;
}

void sigAction :: signalHandle(int sig __attribute__((unused)),
             siginfo_t *si __attribute__((unused)),
             void *unused __attribute__((unused))) {
        fanotify_mark(fanFd, FAN_MARK_FLUSH, 0, 0, NULL) ;
}

int Fanotify:: setSpecialIgnored(int dstFd, const std::string paths) {
    unsigned int flag = (FAN_MARK_ADD|FAN_MARK_IGNORED_MASK
                         |FAN_MARK_IGNORED_SURV_MODIFY) ;
    uint64_t mask = FAN_ALL_EVENTS|FAN_ALL_PERM_EVENTS ;
          if (strcmp("/var/log/audit/audit.log", paths.c_str()) &&
          strcmp("/var/log/messages", paths.c_str()) &&
          strcmp("/var/log/wtmp", paths.c_str()) &&
          strcmp("/var/run/utmp", paths.c_str()))
          return 0;
    std::string aa = "" ;
    return makeObject(dstFd, aa, mask, flag) ;
}   

int Fanotify::setIgnoreMask(int fd, uint64_t mask) {
    unsigned int flag = FAN_MARK_ADD|FAN_MARK_IGNORED_MASK  ;
    return makeObject(fd, "",  mask, flag) ;
}

int Fanotify :: getNotifyFD() {
    return fd ;
}

int Fanotify::getEvent() {
    char buf[4096] ;
    int len = read(fd, buf, sizeof(buf)) ;
    struct fanotify_event_metadata* metadata ;
    std::string paths ;
    metadata = (fanotify_event_metadata*)buf ;
    while(FAN_EVENT_OK(metadata, len)) {
        //处理matadata
        metadata = FAN_EVENT_NEXT(metadata, len) ;
        if(metadata->mask&FAN_OPEN) {
            std :: cout << "文件被打开" << std:: endl ;
        }   
        if(metadata->mask&FAN_CLOSE) {
            if(metadata->mask&FAN_CLOSE_WRITE) {
                std:: cout << "write" << std:: endl  ;
            }   
            if(metadata->mask&FAN_CLOSE_NOWRITE) {
                std :: cout << "close" <<std:: endl ;
            }
        }
        if(metadata->mask&FAN_MODIFY){
            std::cout << "修改" << std :: endl ;
        }
        if(metadata->mask&FAN_OPEN_PERM) {
            printf("open perm") ;
        }
        if(metadata->mask&FAN_ACCESS_PERM) {
            printf("access-perm") ;
        }
    }
    return 1 ;
}   

