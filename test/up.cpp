#include <iostream>
#include <vector>
using namespace std ;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size() ;
        int flag = 1 ;
        for(int i=1; i<len; i++) {
            if(nums[i-1]>nums[i]) {
                flag = 0 ;
                nums[i-1] = nums[i-1] ;
                break ;
            }
        }
        if(flag == 1) return true ;
        for(int i=0; i<len; i++) {
            for(int k=i+1; k<len; k++) {
                if(nums[i] > nums[k]) {
                    return false;
                }
            }
        }   
        return true ;
    }
};

int main() {
    Solution ss ;
    vector<int>ls{4,2,3} ;
    cout << ss.checkPossibility(ls)<< endl  ;
    vector<int>ls1{3, 4,2,3} ;
    cout <<ss.checkPossibility(ls1)<< endl ;

}

