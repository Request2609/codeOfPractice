#include <iostream>
class A {
public :
    A() {a=1;}
    virtual ~A(){a=0;}
    virtual void print() {  
        std::cout << "li ba dan!" << std::endl;
    }
    int a ;
};

class B:public A {
public :
    B() {}
    ~B() {}
    void print()const{
        std::cout << "wang ba dan!" << std::endl;
     }
};

int main()
{
    A* a = new B ;
    a->print() ;
    return 0;
}

