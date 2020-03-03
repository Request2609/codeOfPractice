#include <iostream>

int main()
{
    int a = 1 ;
    //不能通过指针修改所指向的变量的值
    const int* p= &a ;
    int b= 10 ;
    //但是可以通过该指针指向其他变量的地址
    p = &b ;
    std::cout << *p << std::endl ;
    int const*q = &a ;
    std::cout << *q << std::endl ;
    q = &b ;
    
    //不能使用u指向其他的值
    int* const u =&a;
    std::cout << *u << std::endl ;
    return 0;
}

