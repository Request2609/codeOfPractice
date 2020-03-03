#include <iostream>
class A{
public :
    A() {
    }
    A& operator=(const A& aa) {
        this->a = aa.a ;
        return *this ;
    } 
    A(const A&aa) {
        a = aa.a ;
    }
    A*operator&(A&aa) {
        return &aa ;
    }
    ~A() {
    }
    int a ;
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

