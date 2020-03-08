#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2) {
            return  n ;
        }
        int num = 1 ;
        int num1 = 2 ;
        int sum = 0 ;
        for(int i=3; i<n; i++) {
            sum = num+num1 ;
            num = num1 ;
            num1 = sum ;
        }
        return sum ;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

