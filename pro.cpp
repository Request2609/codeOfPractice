#include <iostream>
class A {
public :
    A() {
    }
    virtual ~A() {

    }
    virtual void test() {
        std::cout << "这是父类" << std :: endl ;
    }
    void print(int b) {
        std::cout << b << std::endl ;
    }
    void test1() {
        std::cout << "重载" << std::endl ;
    }
    int a ;
};
class B :public A {
public :
    B() {
    }
    ~B() {}
    virtual void test() {
        std::cout << "这是子类" << std :: endl ;
    }
} ;

int main() {
    B* b = new B() ;
    b->test() ;
    //安全
    auto a = static_cast<A*>(b) ;
    a->test1() ;
    //安全
    auto dy = dynamic_cast<A*>(b) ;
    dy->test1() ;
    //当父类指针指向父类对象的时候，
    //使用dynamic_cast是不能进行强制转换到其任何子类的
    A*ss = new A() ;
    auto s = dynamic_cast<B*>(ss) ;
    if(s == NULL) {
        std::cout << "不能转换" << std::endl ;
        delete(ss) ;
    }
    else {
        std::cout << "能转换" << std::endl ;
        delete ss ;
    }
    //当父类指针指向任意子类对象时
    //可以通过dynamic_cast实现基类向子类的转化，安全
    ss = new B() ;
    auto tt = dynamic_cast<B*>(ss) ;
    if(tt != NULL) {
        std::cout << "可以转换" << std::endl ;
        delete ss ;
        return 1;
    }
    std::cout << "不能转换~~" << std::endl;
    delete b ;
}

