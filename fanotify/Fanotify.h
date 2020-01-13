#pragma once
#include <errno.h>
#include <inttypes.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <linux/fanotify.h>

#include "fanotify-syscalllib.h"

#define FANOTIFY_ARGUMENTS "cdfhmnp"

class sigAction {
public :
    static void signalHandle(int, siginfo_t*, void*) ;
private:
    static struct sigaction sa;
    static int fanFd ;
} ;

class Fanotify {
public:
    Fanotify() ;
    ~Fanotify() ;
    void setSigHandle() ;
    void fanotifyInit() ;
    //选择检测对象
    void setNotifyObject() ;
    int setSpecialIgnored(int dstFd, const std::string paths) ;
    int makeObject(int fd, const std:: string path, 
                    uint64_t mask, unsigned int flags) ;
    int setIgnoreMask(int fd, uint64_t mask) ;
    int getNotifyFD() ;
    int getEvent() ;
private:
    int fd ;
    uint64_t fMask ;
    unsigned int markFlag ;
    int fanMask ;
    int initFlag ;
};

