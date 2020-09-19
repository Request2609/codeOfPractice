#include <iostream>
#include <vector>
using namespace std ;
//非递归
class Solution {
public:
    int jumpFloorII(int number) {
       if(number == 0) return 0 ; 
       vector<int>ls ;
       ls.reserve(number) ;
       for(int i=0; i<number; i++) {
            int sum = 0 ;
            //求0~n的和
            for(int j=0; j<i; j++) {
                sum+=ls[j] ;
            }
            //ls[n]为调到第n+1级台阶的方法数
            ls[i] = sum+1 ;
       }
       return ls[number-1] ;
    }

    //递归方法
    int jumpFloor(int target) {
        if(target == 0 || target==1) {
            return 1 ;
        }
        if(target == 2) {
            return 2 ;
        }
        int sum = 0 ;
        for(int i=0; i<target; i++) {
            sum+=jumpFloor(i) ;
        }
        return sum ;
    }
};

//递归方法

int main() {

    return 0;
}

