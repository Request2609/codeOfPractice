#pragma once
#include <errno.h>
#include <inttypes.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <linux/fanotify.h>
//#include "Epoll.h"
#include "fanotify-syscalllib.h"

#define FANOTIFY_ARGUMENTS "cdfhmnp"

const int OPEN = 1 ;
const int MODIFY = 2 ;
const int CLOSE_MODIFY = 3;
const int CLOSE = 4 ;

class Fanotify {
public:
    Fanotify() ;
    ~Fanotify() ;
    //选择检测对象
    void setNotifyObject(std::string path) ;
    //获取句柄
    int getNotifyFD() ;
    void startListen() ;
    //开始监听函数
private:
    int selectEvent() ;
    int getEvent(const struct fanotify_event_metadata* metadata) ;
    //设置检测对象的
    int makeObject(const std:: string path);
 //   std::shared_ptr<epOperation>ep ;
    int fanFd ;
    uint64_t fMask ;
    unsigned int markFlag ;
    int fanMask ;
    int initFlag ;
};

