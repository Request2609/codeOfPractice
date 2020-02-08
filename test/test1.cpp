#include <iostream>
#include <memory>
using namespace std ;
class A ;
class B {
public :
    B() {}
    ~B() {}
    int b ;
    shared_ptr<A>a ;
};
class A {
public :
    A() {}
    ~A() {}
    weak_ptr<B>b ;
};

int main(){
    A a ;
    a.b = make_shared<B>() ;
    B b ;
    b.a = make_shared<A>() ;
    return 0;
}

