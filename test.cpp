#include <iostream>
#include <ucontext.h>

int main() {
    ucontext_t context ;
    getcontext(&context) ;
    puts("hello world!") ;
    setcontext(&context) ;
    return 0;
}

