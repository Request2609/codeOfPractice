#include <iostream>
class A {
public :
    A(int a):a(a) {}
    operator bool()const{ return true ; }
    int a; 
};

class B {
public :
    explicit B(int c) {}
    explicit operator bool()const{ return true ; }
    int b ;
};
int main()
{
    //没有申明为explicit，可以赋值初始化
    A a = 1 ;
    std::cout << a.a << std::endl ;
    //explicit用于构造函数，不可以被赋值初始化
    B b = 0 ; //error
    B f(0) ;
    //被explicit修饰转换函数可以从b向bool的转化
    bool tmp(f) ;
    tmp = 1 ;
    
    return 0;
}

