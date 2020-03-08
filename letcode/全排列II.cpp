#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
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
            if(check(index, i, nums)) {
                swap(nums[i], nums[index]) ;
                getRes(tmp, nums, index+1) ;
                swap(nums[i], nums[index]) ;
            }
        }
    }
    bool check(int start, int end, std::vector<int>num) {
        for(int i=start; i<end; i++) {
            if(num[i] == num[end]) {
                return false ;
            }
        }
        return true ;
    }
    void swap(int& num, int& num1) {
        int tmp = std::move(num) ;
        num = std::move(num1) ;
        num1 = std::move(tmp) ;
    }

};
int main()
{ 
    Solution ss ;
    std::vector<int>ls ;
    while(1) {
        int a ;
        std::cin >> a ;
        if(a == -1) break ;
        ls.push_back(a) ;
    }
    auto lis = ss.permuteUnique(ls) ;
    int len = lis.size() ;
    for(int i=0; i<len; i++) {
        int size = lis[i].size() ;
        for(int j=0; j<size; j++) {
            std::cout << lis[i][j] << " " ;
        }
        std::cout << std::endl ;
    }

    return 0;
}

