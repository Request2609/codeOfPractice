#include <iostream>
using namespace std ;
/*
 *一只青蛙一次可以跳上1级台阶，
 也可以跳上2级。
 求该青蛙跳上一个n级的台阶
 总共有多少种跳法（先后次序不同算不同的结果）。
 * */

class Solution {
public:
    int jumpFloor(int number) {
        int form = 1 ;       
        int form1 = 2 ;
        int target =0 ;
        if(number == 0) {
            return 0 ;
        }
        if(number ==1) {
            return 1 ;
        }
        if(number == 2) {
            return 2 ;
        }
        else {
            for(int i=3; i<=number; i++) {
                target = form+form1 ;
                form = form1 ;
                form1 = target ;
            }
        }
        return target ;
    }
};
int main()
{
    Solution ss ;
    cout << ss.jumpFloor(40) << endl;
    return 0;
}

