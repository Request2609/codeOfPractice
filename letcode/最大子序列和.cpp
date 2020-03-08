#include <iostream>
#include <vector>
///dp
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxs = INT32_MIN ;
        int len = nums.size() ;
        int index = 0 ;
        int tmp = 0 ;
        std::vector<int>ls ;
        while(index<len) {
            tmp+=nums[index] ;
            std::cout << tmp << "   "<<index << std::endl ;
            if(tmp >= 0) {
                if(maxs<tmp) {
                    maxs = tmp ;
                }
            }
            if(tmp<0&&index>=0) {
                if(tmp>maxs) {
                    maxs = tmp ;
                }
                tmp = 0 ;
            }
            index++ ;
        }
        return maxs ;
    }
};

int main() {
    Solution ss ;
    std::vector<int>ls ;
    int num ;
    std::cin>> num ;
    while(num--) {
        int a ;
        std::cin >> a ;
        ls.push_back(a) ;
    }
    std::cout <<  ss.maxSubArray(ls) << std::endl ;
    return 0;
}

