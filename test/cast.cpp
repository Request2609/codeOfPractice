#include <iostream>

int main(int argc, char const *argv[])
{
    const int * ptrConst = new const int(10);
    printf("%d\n" , *ptrConst);
    int intAddr = reinterpret_cast<int>(ptrConst);
    printf("%d\n" , intAddr);
    int * ptr = reinterpret_cast<int *>(intAddr);
    *ptr = 11;
    printf("%d\n",*ptr );
    delete ptrConst;
    ptrConst = NULL;
    while(1);
}
