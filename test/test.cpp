#include <iostream>
#include <memory>

class B{
public :
    void print() {
        std::cout << b << std::endl ;
    }
    int b ;
};
int main() {
    
    std::unique_ptr<B>ptr = std::make_unique<B>() ;
    ptr->b = 10 ;
    //之后ptr失效
    auto tmp = std::move(ptr) ;
    tmp->print() ;
    
    return 0; 
}

