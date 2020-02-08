#include <iostream>
#include <sys/timerfd.h>
#include <unistd.h>
#include <time.h>
#include <vector>
#include <memory>
#include "aeEpoll.h"

using namespace std;

int main() {
    struct timespec now ;
    if(clock_gettime(CLOCK_REALTIME, &now) == -1) {
        return -1 ;
    }
    struct itimerspec itime ;
    //设置初始时间
    itime.it_value.tv_sec = now.tv_sec+3 ;
    itime.it_value.tv_nsec = now.tv_nsec ; 

    //设置间隔时间
    itime.it_interval.tv_sec = 3 ; //seconds
    itime.it_interval.tv_nsec = 0 ; //(ns)//精度太高不需要
    
    int fd = timerfd_create(CLOCK_REALTIME, 0) ;
    if(fd < 0) {
        return -1 ;
    }
    if(timerfd_settime(fd,TFD_TIMER_ABSTIME, &itime, NULL) == -1) {
        return -1 ;
    }
    vector<epoll_event>ls ;
    int sum = 0 ;
    shared_ptr<aeEpoll>aep = make_shared<aeEpoll>() ;
    aep->epCreate(1024) ;
    aep->add(fd, EPOLLIN) ;
    while(1) {
        int num = aep->wait(ls) ;
        for(int i=0; i<num; i++) {
            int fd = ls[i].data.fd ;
            if(ls[i].events&EPOLLIN) {
                uint64_t res ;
                int ret = read(fd, &res, sizeof(res)) ;
                if(ret == -1) {
                    return -1 ;
                }
                sum += res ;
                cout << sum<<"   " << res << endl ;
            }
        }
    }
    close(fd) ;
    return 0;
}

