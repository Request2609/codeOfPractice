#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    //找出左边界，再找出右边界就行，注意找左边界的时候，由右侧
    //逼近，找右边界的时候，由左侧逼近，就行
    std::vector<int> searchRange1(std::vector<int>& nums, int target) {
        std::vector<int>res(2,-1) ;
        if(nums.empty()) return res ;
        int n=nums.size(), l=0, r=n-1;
        while(l<r) {
            int m = l+(r-l)/2 ;
            //target在nums 1~m数组半部分
            if(nums[m]>=target) {
                r = m ;
            }
            //要是不在，重置l
            else l = m+1 ;
        }
        //没找到左边等于target的值
        if(nums[l] != target) return res ;
        res[0] = l ;
        r = n ;
        //找右边界
        while(l<r) {
            int m = l+(r-l)/2 ;
            if(nums[m] <= target) l=m+1 ;
            else r = m ;
        }
        res[1] = l-1 ;
        return res ;
    }
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
           int left = 0 ;
           int right = nums.size()-1 ;
           std::vector<int>ls ;
           int mid = 0 ;
           int tmp = 0 ;
           int flag = 0 ;
           while(right!=0&&left <= right) {
               mid = (left+right)/2 ;
               tmp = mid ;
            
               while(tmp<=right&&nums[tmp] == target) {
                    flag = 1 ;
                    ls.push_back(tmp) ;
                    tmp++ ;
               }
               if(flag == 1) tmp = mid-1 ;
               while(flag==1&&tmp>=left&&nums[tmp]==target) {
                    ls.push_back(tmp) ;
                    tmp -- ;
                    sort(ls.begin(), ls.end()) ;
               }
               if((flag == 1 && ls.size() == 1)||tmp<left) {
                    if(tmp < left) break ;
                    ls.push_back(ls[0]) ;
                    break ;
               }

               if(nums[mid] > target) {
                    right = mid -1 ;
               }
               if(nums[mid] < target) {
                    left = mid+1 ;
               }
           }
           if(ls.size() == 1) {
                ls.push_back(ls[0]) ;
                return ls ;
           }
           if(nums.size()==1&&target==nums[0]) {
               ls.push_back(0) ;
               ls.push_back(0) ;
               return ls ;
           }
           if(flag == 0) {
               ls.push_back(-1) ;
               ls.push_back(-1) ;
           }
           sort(ls.begin(), ls.end()) ;
           return ls ;
    }
};

int main() {
    Solution ss ;
    std::vector<int>ls ;
    while(1) {
        int a ;
        std::cin >> a ;
        if(a == -1) break ;
        ls.push_back(a) ;
    }
    int num ;
    std::cin >> num ;
    auto se = ss.searchRange(ls, num) ;
    for(auto a : se) {
        std::cout << a << std::endl ;
    }
    return 0;
}

