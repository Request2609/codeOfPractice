#include <iostream>
using namespace std ;
int main()
{
    int b = 10 ;
    int&a =b;
    std::cout << &a <<std::endl ;
    int c = 89 ;
    a = c ;

    std::cout << &a <<std::endl ;
    cout << b << endl ;
    std::cout << "Hello world" << std::endl;
    return 0;
}

