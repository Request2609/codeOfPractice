#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()) ;
        int closeNum = nums[0]+nums[1]+nums[2] ;
        //选定的要求和的个数的下标
        int digit1_index , digit2_index, digit3_index ;
        int max_digit_index = nums.size()-2 ;
        //从右往左遍历一遍数组 ，
        //遍历到第i个元素时则认为该元素的为第一个选定元素 
        //另外两个是从钙元素的右边选择（即从第i+1到end之间选另外两个元素）
        for(int i=0; i<max_digit_index; i++) {
            digit1_index = i ;
            digit2_index = i+1 ;
            digit3_index = nums.size()-1 ;
            int tmp_sum = nums[digit1_index]+nums[digit2_index]+nums[digit3_index] ;
            //第一个数字实在当前时刻是指定不变了
            //下面这个训话要做的事情就是确定第一个数是nums[i]的情况下
            //剩下两个数该怎么选
            while(digit2_index<digit3_index) {
                if(abs(tmp_sum-target)<abs(closeNum-target)) 
                    closeNum = tmp_sum ;
                //判断是否为0，要是就直接返回
                int diff = target-tmp_sum ;
                if(diff==0) {
                    return target ;
                }
                if(diff > 0) {
                    //target比tmp_sum大，所以为了缩小差距就应该增大tmp_sum
                    //但是第三个数已经是最大的，那就增大第二个数
                    digit2_index++ ;
                }
                else {
                    //要是小于的话，就左移动第三个指针
                    digit3_index-- ;
                }
                tmp_sum = nums[digit1_index]+nums[digit2_index]+nums[digit3_index] ;
            }
        } 
        return closeNum ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

