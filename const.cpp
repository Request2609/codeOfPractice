#include <iostream>

int main() {
    const int tmp = 10 ;
    int*p = const_cast<int*>(&tmp) ;
    *p = 11 ;
    std::cout <<*p<<"     "<< tmp << std::endl ;
    return 0;
}

