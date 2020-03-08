#include <iostream>
#include <memory>
class A {
public :
    std::shared_ptr<A>getPtr() {
        return std::shared_ptr<A>(this) ;
    }
};

class B : public std::enable_shared_from_this<B> {
public :
    std::shared_ptr<B> getPtr() {
        return shared_from_this() ;
    }
};

int main()
{
    B b ;
    auto s = b.getPtr() ;
    std::cout << s.use_count() << std::endl ;
/*    //这也是一个智能指针
    std::shared_ptr<A>ptr = std::make_shared<A>() ;
    //这是一个智能指针，导致程序结束后二次析构A对象
    auto res = ptr->getPtr() ;
    //两个智能指针指向同一个对象，
    //引用计未增加，导致对象析构两次
    //引用计数为1？
    std::cout << ptr.use_count() << std::endl ;
    
    auto b = std::make_shared<B>() ;
    auto s = b->getPtr() ;
    //引用计数为2？
    std::cout << s.use_count() << std::endl ;*/
    return 0;
}

