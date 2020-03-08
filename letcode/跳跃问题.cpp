#include <iostream>
#include <vector>
class Solution {
public:
    //从后往前遍历数组，如果遇到的元素可以到达最后一行，
    //截断后边的元素，否则继续前行，若最后剩下的元素的大于1个，判断是
    //假，否则为真
    bool canJump(std::vector<int>& nums) {
        int n = 1 ;
        int len = nums.size() ;
        for(int i=len-2; i>=0; i--) {
            if(nums[i]>=n) {
                n = 1 ;
            }
            else {
                n++ ;
            }
            if(i==0&&n>1) {
                return false ;
            }
        }
        return true ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

