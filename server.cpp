#include <iostream>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include  <unistd.h>    
#include  <sys/types.h>  
#include  <sys/socket.h>  
#include  <sys/ioctl.h>  
#include  <netinet/in.h>  
#include <netinet/tcp.h>
#include  <arpa/inet.h>  
#include  <netdb.h>  

int open_listenfd(char *port);

int main(int argc, const char * argv[]) {
    int listenfd, connfd = 0;
    socklen_t clientlen;
    listenfd = open_listenfd("8888");
    
    int connd = accept(listenfd, (struct sockaddr*)&clientlen, &clientlen);
    if (connfd < 1) {
        printf("appect error");
    }
    char buf[1024] ;
    std::cout << "接受到一个新事件" << std::endl ;
    int a = 0 ;
    //关闭描述符，发起第四次挥手，关闭了写端
    while(1) {
        int ret = read(connfd, buf, sizeof(buf)) ;
        if(ret < 0) {
            std::cout << strerror(errno) << "      " << __LINE__ << std::endl ;
        }
        std::cout <<"接收到数据:" <<  a << std::endl ;
    }
    close(connfd);
    close(listenfd);
    return 0;
}
int open_listenfd(char *port) {
    int tmp = 1;
    struct addrinfo hints, *listp, *p;
    int listenfd = 0, optval = 1;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG; // 被动的  任何IP address
    hints.ai_flags |= AI_NUMERICSERV; // use port number
    getaddrinfo(NULL, port, &hints, &listp);
    
    for (p = listp; p ; p = p->ai_next) {
        if ((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
            continue;
        }
    //    setsockopt(listenfd, IPPROTO_TCP, TCP_DEFER_ACCEPT, (const char*)&tmp, sizeof(int)) ;
  //      setsockopt(listenfd, IPPROTO_TCP, TCP_NODELAY, (const char*)&tmp, sizeof(int)) ;
        
        setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
        
        if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0) {
            break;//Success
        }
        close(listenfd);
    }
    
    freeaddrinfo(listp);
    if (!p) {
        return -1;
    }
    if (listen(listenfd, 30) < 0) {
        close(listenfd);
        return -1;
    }
    return listenfd;
}

