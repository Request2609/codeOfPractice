#include <iostream>
#include <map>
using namespace std ;
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <csignal>

#define MAXLINE 120

int main(int argc, char *argv[]) {
    signal(SIGPIPE, SIG_IGN);  // 忽略 SIGPIPE 信号
    //1.创建一个侦听socket
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        std::cout << "create listen socket error." << std::endl;
        return -1;
    }

    //2.初始化服务器地址
    struct sockaddr_in bindaddr;
    bindaddr.sin_family = AF_INET;
    bindaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bindaddr.sin_port = htons(8888);
    if (bind(listenfd, (struct sockaddr *) &bindaddr, sizeof(bindaddr)) == -1) {
        std::cout << "bind listen socket error." << std::endl;
        return -1;
    }

    //3.启动侦听
    if (listen(listenfd, SOMAXCONN) == -1) {
        std::cout << "listen error." << std::endl;
        return -1;
    }
    /**
     * 服务端连续写两次数据到客户端
     */
    while (true) {
        struct sockaddr_in clientaddr;
        socklen_t clientaddrlen = sizeof(clientaddr);
        //4. 接受客户端连接
        int clientfd = accept(listenfd, (struct sockaddr *) &clientaddr, &clientaddrlen);
        if (clientfd != -1) {
            // 假设此时 client 奔溃, 那么 server 将接收到 client 发送的 FIN
            sleep(5);
            // 写入第一条消息
            char msg1[MAXLINE] = {"first message"};
            ssize_t n = write(clientfd, msg1, strlen(msg1));
            printf("write %ld bytes\n", n);
            // 此时第一条消息发送成功，server 接收到 client 发送的 RST
            sleep(1);
            // 写入第二条消息，出现 SIGPIPE 信号，导致 server 被杀死
            char msg2[MAXLINE] = {"second message"};
            n = write(clientfd, msg2, strlen(msg2));
            printf("%ld, %s\n", n, strerror(errno));
        }

        close(clientfd);
    }
    //关闭侦听socket
    close(listenfd);
    return 0;
}
