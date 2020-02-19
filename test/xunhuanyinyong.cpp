#include <iostream>
#include <memory>
using namespace std  ;

class A ;
class B {
public :
    B() {
        cout << "创建B" << endl ;
    }
    ~B() {
        cout << "释放B" << endl ;
    }
    void print() {
        cout << "hello world!" << endl ;
    }

    shared_ptr<A>a ;
};
class A {
public :
    A() {
        cout << "创建A" << endl ;
    }
    ~A(){
        cout << "释放A" << endl ;
    }
    weak_ptr<B>b ;
} ;

int main() {
    shared_ptr<A> a = make_shared<A>() ;
    shared_ptr<B>b = make_shared<B>() ;
    a->b = b ;
    a->b.lock()->print() ;
    return 0;
}

