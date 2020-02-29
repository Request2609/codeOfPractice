#include <iostream>
#include <vector>
class A {
public :
    A() {
    }
    void print(A*q) {
        //通过const_cast向this指针赋值
        A*p = const_cast<A*>(this) ;
        p = q ;
    }
};

void func(int&&a) {
    std::cout << a << std::endl ;
}

int main()
{
    int a = 1 ;

    int&b = a ;

    std::vector<int>ls ;
    ls.push_back(1) ;
    ls.push_back(ls.back()) ;
    for(auto s:ls) {
        std::cout << s << std:: endl; 
    }
    func(1) ;    
    return 0;
}

