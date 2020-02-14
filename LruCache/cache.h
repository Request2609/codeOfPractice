#pragma once
#include <iostream>
#include <memory>
using namespace std ;

//简单的lru缓存程序
struct node {
    int val ;
    shared_ptr<struct node>nexts ; 
    shared_ptr<struct node>pre ;
} ;

class cache {
public:
    cache(int n):count(0), num(n), head(nullptr), tail(nullptr) {}
    ~cache() {}
    void setNum(int n) {
        num = n ;
    }
    int insert(shared_ptr<node>data) ;
    bool accessData(int num) ;
private:
    void moveLast(shared_ptr<node>cur) ;
    int count ;
    int num ;
    shared_ptr<struct node>head ;
    shared_ptr<struct node>tail ;
};

