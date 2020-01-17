#include <iostream>
#include <vector>
#include <set>

using namespace std ;
class Solution{
public:
    vector<vector<int>>res ;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ls ;
        getRes(nums, 0) ;                  
        for(auto s:res) {
            ls.push_back(s) ;
        }   
        return ls ;
    }

    void getRes(vector<int>nums, int index) {
        int size = nums.size() ;
        if(index >= size) {
            res.push_back(nums) ;
            return  ;
        }
        for(int i=index; i<size; i++) {
            if(isSwap(nums, index, i)) {
                swap(i, index, nums) ;
                getRes(nums, index+1) ;
                swap(i, index, nums) ;
            }
        }
    }
    
    bool isSwap(vector<int>&nums, int start, int end) {
        for(int i=start; i<end; i++) {
            if(nums[i] == nums[end]) {
                return false ;
            }
        }
        return true ;
    }
    void swap(int index1, int index, vector<int>&nums) {
        int tmp = move(nums[index1]) ;
        nums[index1] = move(nums[index]) ;
        nums[index] = move(tmp) ;
    }
};
int main()
{
    Solution ss ;
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1)break ;
        ls.push_back(a) ;
    }
    ss.permuteUnique(ls) ;
    return 0;
}

