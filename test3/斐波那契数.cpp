#include <iostream>
#include <vector>
using namespace std ;
class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0) {
            return 0 ;
        }
        if(n==1||n==2) return 1 ;
        int tmp = 1 ;
        int num= 1 ;
        for(int i=3; i<n; i++) {
            num = tmp+num ;
            tmp = num-tmp ;
        }
        return num ;
    }
};
int main()
{
    Solution ss ;
    cout << ss.Fibonacci(5) << endl ;
    cout << ss.Fibonacci(7) << endl ;
    return 0;
}

