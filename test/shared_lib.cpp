#include "shared_lib.h"

void swap(int&a, int&b) {
    int tmp = std::move(a) ;
    a = std::move(b) ;
    b = std::move(tmp) ;
}

int add(int a, int b) {
    return a+b ;
}
