#include <iostream>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <netdb.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>

int open_clientfd(char *hostname,char *port);
int main(int argc, char * argv[]) {
    int clientfd;
    
    if (argc != 3) {
        printf("must three params \n");
        return 0;
    }
    char *hostname = argv[1];
    char *port = argv[2];
    clientfd = open_clientfd(hostname,port);
    char str[64];
    if (clientfd < 0) {
        return 0;
    }
    read(clientfd,str,64);
    printf("%s", str);
    close(clientfd);
    return 0;
    
}

void handle(int signo) {
    std::cout << "接收到管道信号" << std::endl ;
}

int open_clientfd(char *hostname, char *port)
{
    signal(SIGPIPE, handle) ;
    int clientfd, rc;
    struct addrinfo hints, *listp, *p;
    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags |=  AI_ADDRCONFIG;
    hints.ai_flags = AI_NUMERICSERV;
    if ((rc = getaddrinfo(hostname, port, &hints, &listp)) != 0) {
        printf("getaddrinfo: failed\n");
        return -2;
    }
    
    for (p = listp; p ; p = p->ai_next) {
        if ((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
            continue;/*socket faied try the next*/
        }
        
        if (connect(clientfd, p->ai_addr, p->ai_addrlen) == -1) {
            break ;
        }
        char buf[1024] ;
        int a = 10 ;
        while(1) {
            std::cin >> buf ;
            //故意一直写数据
            if(a == -1) break ;
            int ret = write(clientfd, buf, sizeof(buf)) ;
            if(ret < 0) {
                std::cout << __LINE__ << "   "  << strerror(errno) << std::endl ;
            }
        }
        if (close(clientfd) < 0) {
            printf("open_lientfd: close failed\n");
            return -1;
        }
        
    }
    freeaddrinfo(listp);
    if (!p) { 
        printf("All connects faied \n");
        return -1;
    } else {
        return clientfd;
    }
}



