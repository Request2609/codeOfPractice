#include <iostream>
#include <memory>

class A {
public :
    int a ;
};

int main() {
    std::shared_ptr<A>ptr ;
    std::weak_ptr<A>wptr ;
    ptr= std::make_shared<A>() ;
    wptr = ptr ;
    std::cout << ptr.use_count()<<"     " << wptr.use_count()<< std::endl ;
    ptr->a = 1 ;
    auto p = wptr.lock() ;
    if(wptr.expired()) {
        std::cout << "失效" << wptr.use_count()<< std::endl ;
    }
    return 0;
}

