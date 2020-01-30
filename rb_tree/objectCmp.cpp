#include <iostream>
using namespace std ;

class A{
public :
    int operator() (int a, int b){
        return a-b ;
    }
} ;
template<class T, class T2>                                                                                                                                                                   
class Test {
private :
    T2 comp ;
    T data ;
public :
    int operator==(Test t) {
        bool ret = comp(t.data, data) ;
        if(ret >= 0) {
            return 1 ;
        }
        return 0 ;
    }
    void setData(T t) {
        data = t ;
    }
    int getData() {
        return data ;
    }
} ;
int main()
{
    Test<int, A>tt ;
    Test<int, A>tt1 ;
    tt.setData(10) ;
    tt1.setData(199) ;
    if(tt == tt1) {
        cout << "大于相等" << endl ;
    }
    else{
        cout << "小于"<< endl ;
    }
    return 0;
}

