#include <iostream>

class A {
public :
    A() {
        std::cout << "构造" << std::endl ;
    }
    A(const A aa)  {
        std::cout << "拷贝构造" << std :: endl ;
    }
    A(const A&aa) {
        std::cout << "移动构造函数" << std::endl ;
    }

    A& operator=(const A& aa) {
        std::cout << "赋值构造" << std::endl ;
        a= aa.a ;
        return *this ;
    }
    int a ;
} ;

void func(A& a) {
    std::cout << "移动构造" << std::endl ;
}
void func(const A&&a) {
    std::cout << "右值引用" << std::endl ;
}

A func1(A a) {
}

int main()
{
    A a ;
    func(a) ;
    //func(std::move(a)) ;
    func1(std::move(a)) ;
    
    return 0;
}

