#include <iostream>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    volatile const int a = 10 ;
    int * p = const_cast<int*>(&a) ;
    //已经在内存中修改了
    *p = 111 ;
    std::cout << *p << "     " << a << std::endl ;
    return 0;
}

