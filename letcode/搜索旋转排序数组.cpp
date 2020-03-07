#include <iostream>
#include <vector>
class Solution {
public:
    int search1(std::vector<int>&nums, int target) {
        int len = nums.size() ;
        int left = 0 ;
        int right = len-1 ;
        while(left<=right) {
            int mid = (left+right)/2 ;
            if(nums[mid] == target) {
                return mid ;
            }
            //总共分四种情况
            //当中间点小于最右边点
            //右半边是有序的
            //若中间数的大于最右边的数，最左半段是有序的
            //只要在有序半段里面
            else if(nums[mid]<nums[right]) {
                //旋转部分不在右半部分
                if(nums[mid]<target && target<nums[right]) {
                    left=mid+1 ;
                }
                //旋转部分在右半部分
                else {
                    right = mid-1 ;
                }
            }
            else {
                //旋转部分不在左半部分
                if(nums[left]<=target&&target<nums[mid]) {
                    right = mid-1 ;
                }
                else {
                    left = mid-1 ;
                }
            }
        }
        return -1 ;
    }

    int search(std::vector<int>& nums, int target) {
        if(!nums.size()) return -1 ;
        int len = nums.size() ;
        for(int i=0; i<len; i++) {
            if(nums[i] == target) {
                return i ;
            }
        }
        return -1 ;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

