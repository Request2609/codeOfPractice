#include <iostream>
#include <functional>
using namespace std ;
function <void(int,int)> func ;

void swap(int a, int b) {
    int tmp = move(a) ;
    a = move(b) ;
    b = move(tmp) ;
}

template<class T>
std::function< T(T&, T&)> Functional;

// 普通函数
template<class T>
T TestFunc(T& a, T& b)
{
    T tmp = a ;
    a = b ;
    b = tmp ;
    return a+b;
}


template <class T, class T1>
class A {
public :
    T1 comp;
    T a ;
    void sett1(T1 tt) {
        t1 = tt ;
    }

    void seta(T ll) {
        a= ll ;
    }
    T geta() {
        return a ;
    }

    void use(A<T, T1> tt) {
        t1(tt.geta(), a) ;
        cout << tt.geta() << endl ;
        cout << a << endl ;
    }
} ;

int main() {
    return 0;
}

