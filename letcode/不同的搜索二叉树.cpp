#include <iostream>
#include <vector>
class Solution {
public:
    int numTrees(int n) {
        if(n==0||n==1) return n ;
        std::vector<int>total(n+1) ;
        total[0] = 1 ;
        //total[i]表示以1...i为节点组成的二叉树有多少种
        for(int i=1; i<=n; i++) {
            //当前左节点的数量为j个，左节点的数量为0到i-1个
            for(int j=0; j<i; j++) {
                //以1....i为节点组成的二叉搜索树的数量为
                //当前以i节点为分节点，左节点的数量j，右节点的数量i-j-1的总数量
                total[i]+=total[j]*total[i-j-1] ;
            }
        }
        return total[n] ;
    }
};

int main() {
    Solution ss ;
    int a; 
    std::cin >>a ;
    std::cout << ss.numTrees(a) << std::endl ;
    return 0;
}

