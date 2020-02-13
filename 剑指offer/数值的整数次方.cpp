#include <iostream>
using namespace std ;
/*给定一个double类型的浮点
 base和int类型的整数exponent。
求base的exponent次方。
保证base和exponent不同时为0
 * */
class Solution {
public:
    double Power(double base, int exponent) {
        double sum ;
        sum=1 ;
        if(exponent < 0) {
            for(int i=0; i<-exponent; i++) {
                sum*=base ;
            }     
            return 1.0/sum ;
        }
        for(int i=0; i<exponent; i++) {
            sum*=base ;
        }     
        return sum;
    }
};
int main()
{
    Solution ss ;
    cout << ss.Power(2.0, -2) << endl;
    return 0;
}

