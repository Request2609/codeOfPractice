#include <iostream>
#include <memory>
class A {
public :
    A() {}
    virtual ~A() {}
    int a ;
} ;

class B :public A{
public:
    B() {
    }
    virtual void print() {}
    virtual ~B() {}
};

int main()
{   
    std::cout << sizeof(B) << std::endl  ;
  /*  auto a = std::shared_ptr<A>(new A) ;
    std::weak_ptr<A> wptr = a ; 
    std::cout <<wptr.use_count() << std::endl ;
    //将弱引用传进
    std::shared_ptr<A> ptr = wptr.lock() ;
    ptr->a = 1 ;
    std::cout << ptr.use_count() << std::endl ;*/
    return 0;
}

