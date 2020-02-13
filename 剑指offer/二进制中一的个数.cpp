#include <iostream>
#include <vector>
using namespace std ;
/*
 输入一个整数，
 输出该数二进制表示中1的个数。
 其中负数用补码表示。
 * */

class Solution {
public:
    int NumberOf2(int n) {
        int count = 0 ;
        while(n!=0) {
            count+=1 ;
            n&=(n-1) ;
        }
        return count ;
    }
        
     int  NumberOf1(int n) {
         if(n >= 0) {
            return getNum1(n) ;
         }
         else{
            n = -n ;
            int num =  0;
            vector<int>ls ;
            while(n) {
                num=n%2 ;
                ls.push_back(num) ;
                n /=2 ;
            }
            int len = ls.size() ;
            int flag = 0 ;
            int count = 0 ;
            for(int k=len-1; k>=0; k--) {
                if(flag == 0 && ls[k] == 1) {
                    flag = 1 ;
                    count++ ;
                    continue ;
                }
                if(flag == 1&& ls[k] == 0) {
                    count++ ;   
                }
            }
            return count+32-ls.size() ;
         }
     }
     int getNum1(int n) {
         int count = 0 ;
         int res = 0 ;
         while(n) {
            res = n%2 ;
            if(res == 1) count++ ;
            n/=2 ;
         }
         return count ;
     }
};

int main()
{
    Solution ss ;
    cout << ss.NumberOf1(-2147483648) << endl ;
    cout << ss.NumberOf1(-13) << endl ;
    return 0;
}

