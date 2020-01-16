#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
using namespace std ;

int main()
{

    int fd = open("test/aa/2.c", O_RDWR) ;
    const char* buf = "hello world" ;
    getchar() ;
    char bb[1024] ;
    cout << "读文件" << endl ;
    read(fd, bb, sizeof(bb)) ;
    cout << bb << " 长度:"<< strlen(bb)<< endl ;
    write(fd, buf, strlen(buf)) ;
    getchar() ;
    close(fd) ;
    return 0;
}

