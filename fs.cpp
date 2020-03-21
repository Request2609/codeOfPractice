#include <iostream>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd = open("server.cpp", O_RDWR) ;
    char ch[3]  ;
    read(fd, &ch, sizeof(ch)) ;
    std::cout << ch << std::endl ;
    getchar() ;
    close(fd) ;
    return 0;
}

