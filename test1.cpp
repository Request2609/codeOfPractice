#include <iostream>
class A{
public :
    A() {}
    virtual ~A() {
    }
};

int main()
{

    std::cout << sizeof(A)<<"    " << sizeof(std::type_info) << std::endl;
    return 0;
}

