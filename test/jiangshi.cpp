#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std ;
int main()
{
    int status = -1 ;
    pid_t pid ;
    pid = fork() ;
    if(pid < 0) {
        cout << __LINE__ << "      " << __FILE__ << endl ;
        return 1 ;
    }
    if(pid== 0) {
        cout << "进入子进程"<< endl ;
        cout << "子进程退出!" << endl ;
        exit(1) ;
    }
    pid_t wpid  = waitpid(pid, &status, WNOHANG) ;
    cout << "wpid:" << wpid << endl ;
    cout << "这是父进程!" << endl ;
    getchar() ;
    return 0;
    getchar() ;
}

