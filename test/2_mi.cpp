#include <iostream>
using namespace std ;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long a = 1 ;
        while(a <= n) {
            if(a == n) {
                return true ;
            }
            else {
                a=a<<1 ;
            }
        }
        return false ;
    }
};
int main()
{
    Solution ss ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) break ;
        cout << ss.isPowerOfTwo(a) << endl ;
    }
    return 0;
}

