#include <iostream>

class Empty{
public :
    Empty() ; //默认构造方法
    Empty(const Empty&) ; //拷贝构造函数
    ~Empty() ; //析构函数
    Empty&operator=(const Empty&) ; //赋值函数
    const Empty* operator&()const ; //常对象取地址
    Empty*operator&() ; //取地址
} ;

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

