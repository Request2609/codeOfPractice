#pragma once
#include <iostream>
#include <sys/inotify.h>
#include <memory>
#include <unistd.h>
#include <dirent.h>
#include <map>
#include "Epoll.h"


class Inotify {
public:
    Inotify() {}
    ~Inotify() {}
    void AddToEpoll() ;
    void SetPath(std::string path) ;
    void StartListen();
    int ReadEvent(int fd) ;
private:
    void AddToEpoll(std::string p) ; 
    map<int, std::string> fdPathPair ;
    std::string path ;
    std::shared_ptr<epOperation> ep ;
};

