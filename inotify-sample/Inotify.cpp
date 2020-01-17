#include "Inotify.h"

void Inotify::AddToEpoll(string p) {
    int fd = inotify_init() ;
    if(fd < 0) {
        std :: cout << __FILE__ << "   " << __LINE__ << std::endl ;
        return ;
    }
    //检测关闭和移动删除事件
    int ret = inotify_add_watch(fd, p.c_str(), IN_DELETE_SELF|IN_CLOSE|IN_MOVE) ;
    if(ret < 0) {
        std::cout << __FILE__ << "    " << __LINE__ << std:: endl ;
        return  ;
    }
    ep->add(fd, EPOLLIN) ;
}   

void Inotify::AddToEpoll() {
    AddToEpoll(path) ;
}

void Inotify::SetPath(std::string path) {
    
}

void Inotify::StartListen() {
    vector<int>fdList ;
    int num = 0 ;
    while(1) {
        num = ep->wait(-1, fdList) ;
        for(int i=0; i<num; i++) {
            ReadEvent(fdList[i]) ;          
        }
        fdList.clear() ;
    } 
    
}

int Inotify::ReadEvent(int fd) {
    char buf[4096] ;
    struct inotify_event* pevent ;
    int ret = read(fd, buf, sizeof(buf)) ;
    if(ret < 0) {
        std::cout << __LINE__ << "   " << __FILE__ << std::endl ;
        return -1 ;
    }
    pevent = (struct inotify_event*)buf ;
    
}
