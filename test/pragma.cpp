#include <iostream>
//#pragma pack(4)
struct test {
    char c ;
    double m2 ;
    int m3 ;
} ;

class A {
public:
} ;
int main()
{
    std::cout << sizeof(test)<< std::endl;
    return 0;
}


