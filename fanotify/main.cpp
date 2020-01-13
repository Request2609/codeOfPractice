#include <iostream>
#include "Fanotify.h"
#include "Epoll.h"

int main() {
    epOperation ep ;
    Fanotify notify ;   
    notify.fanotifyInit() ;
    int fd = notify.getNotifyFD() ;
    ep.add(fd, EPOLLIN) ;
    ep.wait(-1, &notify) ;
    return 0;
}

