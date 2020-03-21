#include <iostream>

class B {
public:
    B() {}
    virtual ~B() {}
    virtual void print() {}
private:
    int a ;
};

class A : public B {
public:
    A() {}
    ~A() {}
    virtual void printA() {}
    int a ;
};

int main() {

    std::cout << sizeof(A) << std::endl ;
    return 0;
}

