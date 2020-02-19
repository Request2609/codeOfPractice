#include <iostream>
using namespace std;
//模板机制为C++提供了泛型编程的方式，在减少代码冗余的同时可以提供类型安全，
//特化必须在同一个命名空间中进行，可以特化类模板也可以特化函数模板，但类模板可以偏特化和全特化，
//而函数模板只能全特化
//通过全特化模板可以对一个特定参数集合定义当前模板
//类模板和函数模板都可以全特化
//全特化类模板:全特化类模板类名后给出了模板实参，但
//函数模板的函数名后没有给出模板实参
template<typename T>
T max(const T a, const T b)  {

}

template <typename T1, typename T2> 
class Test {

};

template <> 
class Test<int, double> {
    int a ;
    double b ;
} ;

//函数模板
template <> 
int max(const int lhs, const int rhs) {

}


//偏特化，类似于全特化，偏特化是为了给自定义一个参数集合的模板，但偏特化后的模板
//需要进一步的实例化才能形成确定的签名，值得注意的是函数模板不允许偏特化
template<typename T1, typename T>
class B {

} ;
//类的偏特化
template<typename T>
class B<int, T> {
    
} ;
//函数模板不允许偏特化


