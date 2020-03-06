#include <iostream>
#include <math.h>
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0 ;
        double a = fabs(dividend) ;
        double b = fabs(divisor) ;
        long result = exp(log(a)-log(b)) ;

    }
};
int main()
{
    Solution ss ;
    int count , num ;
    std::cin >> num ;
    std::cin >>count ;
    std::cout << ss.divide(num, count) <<std::endl ;
    return 0;
}

