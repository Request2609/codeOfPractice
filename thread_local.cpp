#include <iostream>
#include <thread>

class A {
public :
    int a ;
    void set(int p) {
        a = p ;
    }
    int get() {
        return a ;
    }
};
thread_local A a ;

void func() {
    a.set(1) ;
    std::cout << a.get() << std::endl ;
}

void func1() {
    a.set(9) ;
    std::cout << a.get() << std:: endl ;
}
int main()
{
    a.set(14) ;
    std::cout<< a.get() << std::endl ;
    std::thread t1(func) ;
    std::thread t2(func1) ;
    t1.join() ;
    t2.join() ;
    return 0;
}

