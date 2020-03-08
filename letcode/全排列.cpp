#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>>tmp ;
        int index = 0 ;
        getRes(tmp, nums, index) ;
        return tmp ;
    }
    void getRes(std::vector<std::vector<int>>&tmp, std::vector<int>nums, int index) {
        int len = nums.size() ;
        if(len<=index) {
            tmp.push_back(nums) ;           
            return ;
        }
        for(int i=index; i<len; i++) {
            swap(nums[i], nums[index]) ;
            getRes(tmp, nums, index+1) ;
            swap(nums[i], nums[index]) ;
        }
    }
    void swap(int& num, int& num1) {
        int tmp = std::move(num) ;
        num = std::move(num1) ;
        num1 = std::move(tmp) ;
    }
};

int main()
{

    return 0;
}

