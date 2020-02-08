#include <iostream>
#include <string.h>
using namespace std ;

class A {
public :
    A() {
        cout << "构造A" << endl ;
    }
    virtual ~A() {};
    virtual void print()= 0 ;
};

class B :public A{
public :
    B(){
        print() ;
        cout << "构造B" << endl ;
    }
    ~B() {
        print() ;
        cout << "析构B" << endl ;
    }
    void print() {
        cout << "helo" << endl;
    }
} ;

template<class T>
bool isequal(T&p1, T&p2) {
    return p1 == p2 ;
}

template<>
bool isequal<char*>(char*&p1, char*&p2) {
    return strcmp(p1,p2) ;
}

int main(){ 
    const char* u = "hello";
    const char* t= "wa" ;
    cout << isequal(u, t) << endl ;
    return 0;
}

