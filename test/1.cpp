#include <iostream>

using namespace std;

class Base {
public:
    virtual void f() { cout << "f()" << endl; }
    virtual void g() { cout << "g()" << endl; }
    virtual void h() { cout << "h()" << endl; }
};

int main()
{
    Base t;
    (((void(*)())*((int*)(*((int*)&t)) + 0))   )     ();
    (((void(*)())*((int*)(*((int*)&t)) + 1))   )     ();
    (((void(*)())*((int*)(*((int*)&t)) + 2))   )     ();
    return 0;
}
