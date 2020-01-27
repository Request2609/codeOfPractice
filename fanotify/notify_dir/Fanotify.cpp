#include "Fanotify.h"

Fanotify :: Fanotify() {
}

Fanotify :: ~Fanotify() {
}

int Fanotify:: initFanotify(std::string path) {
    this->paths = path ; 
    ep = make_shared<epOperation>() ;
    return 1 ;
}

void Fanotify:: detectOpenClose(int fanFd) {
    cout << fdAbName[fanFd] << endl ;
    int ret = fanotify_mark(fanFd, FAN_MARK_ADD, FAN_CLOSE|FAN_OPEN, AT_FDCWD, fdAbName[fanFd].c_str()) ;
    if(ret < 0) {
        std:: cout << __FILE__ << "    " << __LINE__ << std:: endl ;
    }
}

//设置监控对象为目录下的子文件
void Fanotify::setNotifyObject(std::string path) {
    std::string tmp = path ;
    uint64_t fanMask = 0;
    int fd = fanotify_init(FAN_CLASS_CONTENT, O_RDWR) ;
    if(fd < 0) {
        std :: cout << __FILE__ << "   " << __LINE__ << "     " << strerror(errno)<< std :: endl ;
        return ;
    }
    fdAbName.insert({fd, path}) ;
    fanMask |= FAN_OPEN_PERM ;
 //   fanMask |= FAN_ALL_PERM_EVENTS ;
    std::cout << "注册路径:"<< path << std::endl ;
    int ret = fanotify_mark(fd, FAN_MARK_ADD, fanMask|FAN_EVENT_ON_CHILD, 
                            AT_FDCWD, path.c_str()) ;
    if(ret < 0) {
        std::cout << __LINE__ <<"   " __FILE__ << "   " << strerror(errno) << std::endl ;
    }
    //设置读事件
    ep->add(fd, POLLIN) ;
    //递归遍历目录
    DIR *dir ;
    struct dirent *ptr ;
    if((dir = opendir(path.c_str())) == NULL) {
        std::cout << __LINE__ << "   " << __FILE__ << std::endl; 
        exit(1) ;
    }
    while((ptr = readdir(dir)) != NULL) {
        //是目录，讲目录加到
        if(ptr->d_type == 4) {
            if(!strcmp(ptr->d_name, ".") || !strcmp(ptr->d_name, "..")) {
                continue ;
            }
            path = tmp+'/'+ptr->d_name  ;
            setNotifyObject(path) ;
        }
        else {
            continue ;
        }
    }
}


void Fanotify ::workCwd() {
    char buf[1024] ;
    getcwd(buf, sizeof(buf)) ;
    absolutePath = buf ;
}
void Fanotify:: startListen() {
    char buf[4096];
    int len = 0 ;
    //使用select监听
    vector<int>fdList ;
    int size = 0 ;
    while((size=ep->wait(-1,fdList))>0) {
        for(int i=0; i<size; i++) {
            //读事件
            len = read(fdList[i], buf, sizeof(buf))  ;
            struct fanotify_event_metadata* metadata = NULL;
            char path[PATH_MAX] ;
            int pathLen ;
            metadata = (fanotify_event_metadata*)buf ;
            if(metadata->fd >= 0) {
                sprintf(path, "/proc/self/fd/%d", metadata->fd) ;
                pathLen = readlink(path, path, sizeof(path)-1) ;
                if(pathLen < 0) {
                    std :: cout << __LINE__ << "     " << __FILE__ << std::endl ;
                    exit(1) ;
                }
                path[pathLen] = '\0' ;
                cout << "正在操作的文件:" << path << endl ;
                getEvent(fdList[i], metadata, len) ;
            }
        }
        fdList.clear() ;
    }
    std::cout << strerror(errno) << std :: endl ;
}

int Fanotify::getEvent(int fanFd, const struct fanotify_event_metadata* metadata, int len) {
    cout << "检查文件事件!----------------------------------------------->" << endl ;
     std::string paths ;
    while(FAN_EVENT_OK(metadata, len)) {
        //处理matadata
        if(metadata->mask&FAN_OPEN) {
            std :: cout << "文件被打开" << std:: endl ;
        }   
        const char* buf = "关闭后可以写";
        if(metadata->mask&FAN_CLOSE) {
            if(metadata->mask&FAN_CLOSE_WRITE) {
                std:: cout << "写关闭" << std:: endl  ;
            }   
            if(metadata->mask&FAN_CLOSE_NOWRITE) {
                std :: cout << "关闭操作" <<std:: endl ;
                const char* buf = "关闭后可以写"  ;
            }
            write(metadata->fd, buf, strlen(buf));
            close(metadata->fd) ;
        }
        if(metadata->mask&FAN_MODIFY){
            std::cout << "修改" << std :: endl ;
        }
        if(metadata->mask&FAN_OPEN_PERM) {
            std::cout << "open perm" << std::endl  ;
           int ret =  handlePerm(fanFd, metadata) ;
           if(ret < 0) {
                cout <<strerror(errno)  << "  " <<__LINE__<< "    " <<__FILE__ << endl ;
                return -1 ;
            }
            //操作文件
            operationFile(metadata->fd) ;
            detectOpenClose(fanFd) ;
        } 
        metadata = FAN_EVENT_NEXT(metadata, len) ;
        if(metadata == NULL) {
            cout << "是空的" << endl ;
        }
    }   
    cout << "检查文件事件结束!----------------------------------------->" << endl ;
    return 1 ;
}   

void Fanotify::operationFile(int fd) {
    const char* buf = "okokokokokokokok" ;
    int ret = write(fd, buf, strlen(buf)) ;
    if(ret < 0) {
        std::cout << "写失败" <<std:: endl ;
    }
    close(fd) ;
}

int Fanotify::handlePerm(int fanFd, const struct fanotify_event_metadata *metadata) {
    struct fanotify_response response_struct;
    int ret;
    response_struct.fd = metadata->fd;
    response_struct.response = FAN_ALLOW;
    cout << "fanFD:" << fanFd << endl ;
    ret = write(fanFd, &response_struct, sizeof(response_struct));
    if (ret < 0) 
        return ret;

    return 0;
}

