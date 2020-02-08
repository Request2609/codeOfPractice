#include <iostream>
#include <math.h>
using namespace std ;
class Solution {
public:
    int reverse(int x) {
        string a = to_string(x) ;
        string rv ;
        int flag = 0 ;
        int noZero = 0 ;
        for(auto s=a.rbegin(); s != a.rend(); s++) {
            if(*s == '-') {
                flag = 1 ;
                continue ;
            } 
            if(*s == '+') {
                flag = 0 ;
                continue ;
            }
            if(noZero == 0&&*s == '0') {
                noZero = 1 ;
                continue ;
            }
            rv+=*s ;
            noZero = 1 ;
        } 
    cout << rv << endl ;
    cout << atoll(rv.c_str()) << endl ;
    long h = (flag ==1)?(-1*atoll(rv.c_str())):atoll(rv.c_str());
    cout << h << endl ;
    cout <<INT32_MAX << endl ;
    if(h > INT32_MAX||h<INT32_MIN) {
        return 0 ;
    }
    return h ;
  }
};
class Solution1{
public :
    int reserve(int x) {
        int rev = 0 ;
        while(x!=0) {
            int pop = x%10 ;
            x/=10 ;
            if(rev > INT32_MAX/10) {
                return 0 ;   
            }
            if(rev <INT32_MIN/10) {
                return 0 ;
            }
            rev = rev*10+pop ;
        }
        return rev ;
    }
};
int main()
{
    Solution1 ss ;
    cout << ss.reserve(15336469) << endl ;
    return 0;
}

