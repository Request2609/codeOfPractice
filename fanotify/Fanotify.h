#pragma once
#include <errno.h>
#include <inttypes.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <iostream>
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
#include <string.h>
#include <linux/fanotify.h>
#include "fanotify-syscalllib.h"


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
    void detectOpenClose() ;
    void detectWrite() ;
    //在监控期间可以操作文件
    void operationFile(int fd) ;
    //开始监听函数
private:
    std::string paths ;
    int handlePerm(const struct fanotify_event_metadata* metadata) ;
    int selectEvent(fd_set* rfd) ;
    int getEvent(const struct fanotify_event_metadata* metadata, int len) ;
    //设置检测对象的
 //   std::shared_ptr<epOperation>ep ;
    int fanFd ;
};

