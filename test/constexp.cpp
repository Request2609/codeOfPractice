#include <iostream>
using namespace std ;
class A {
public :
    constexpr A():a(1), b('c') {}
    int a;
    char b ;
} ;
int main()
{
    A a ;
    a.b = 'a' ;
    return 0;
}


