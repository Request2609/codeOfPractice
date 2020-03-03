#include <iostream>
#include <memory>
class B ;
class A {
public :
    A() {
        std::cout << "构造A" << std::endl ;
    }
    ~A() {
        std::cout << "析构A" << std::endl ;
    }
    int a ;
    std::weak_ptr<B>bptr ;
};

class B {
public :
    B() { 
        std::cout << "构造B" << std::endl ;
    }
    ~B() {
        std::cout << "析构B" << std::endl ;
    }
    std::shared_ptr<A> aptr ;
};

int main() {
    std::shared_ptr<B> btr = std::shared_ptr<B>(new B) ;
    std::shared_ptr<A> atr = std::shared_ptr<A>(new A) ;
    btr->aptr = atr ;
    atr->bptr = btr ;
    auto ptr = atr->bptr.lock() ;
    std::cout << ptr.use_count() << std::endl ;
    return 0;
}

