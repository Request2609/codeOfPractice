#include <iostream>
#include <thread>
#include <memory>
#include <vector>
class A {
public:
    A() {
    }
    int a ;
};

void func(std::shared_ptr<A>p) {
    for(int a=0; a<10; a++) {
        p->a += a ;
    }
    std::cout << p->a << std::endl ;
}
union test{
    char c ;
    int a ;
};

int main() {
    test t ;
    t.a = 1 ;
    //判断大小端
    printf("%d\n", *((int*)(&t.c))) ;
    /*std::shared_ptr<A>ptr = std::make_shared<A>() ;   
    std::thread t(func, ptr) ;
    std::thread t1(func, ptr) ;
    t.join() ;
    t1.join() ;*/ /*
    std::unique_ptr<A>ptr = std::make_unique<A>() ;
    ptr->a = 10 ;
    std::vector<std::unique_ptr<A>>ls ;
    //支持容器操作
    ls.push_back(ptr) ;*//*
    long long a = (long long)1024*1024*1024*3 ;
    char* p = (char*)malloc(a) ;
    if(p == NULL) {
        printf("系统空间不足\n") ;
    }
    else {
        printf("已经分配\n") ;
        getchar() ;
        free(p) ;
    }*/
    return 0 ;
}

