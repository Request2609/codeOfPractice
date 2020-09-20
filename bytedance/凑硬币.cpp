#include <iostream>
#include <vector>
using namespace std ;
/*
 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2:

输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。
示例 3:

输入: amount = 10, coins = [10] 
输出: 1
 */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
            int len = coins.size() ;
            vector<int>dp(len, 0);
            dp[0] = 1 ;
            for(int coin : coins) {
                //记录每添加一种面额的零钱，总金额ｊ的变化
                for(int j=0; j<=amount; j++) {
                    if (j<=coin) {
                        //在上一种零钱状态的基础上增大
                        //例如对于总额为5的，当只有面额为1的零钱时，只有一种可能5×１
                        //当加上面额为2的零钱的时候，除了原来的哪一种可能，还加上了组合了两块钱的，所以就加上此时总额为3的所有组合情况
                        dp[j] = dp[j]+dp[j-coin] ;
                    }
                }
            }
            return dp[amount] ;
    }
    //二维数组解析
    int changes(int amount, vector<int>&coins) {
        int n = coins.size() ;
        vector<vector<int>>dp(n+1, vector<int>(amount+1)) ;
        dp[0][0] = 1 ; //有一种方案凑成0元，那就是一个都不选
        for(int i=0; i<n; i++) {
            for(int j=0; j<=amount; j++) {
                dp[i][j] = dp[i][j-coins[i-1]] ;
            }
        }
        return dp[n][amount] ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

