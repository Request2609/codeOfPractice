#include <iostream>
#include <vector>
using namespace std ;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0 ;
        int right = -1 ;
        int min_num = INT16_MAX ;
        int tmp = 0 ;
        int flag = 1 ;
        while(right < (int)nums.size()) {
            if(tmp >= s) {
                flag = 0 ;
                if(right-left+1 < min_num) {
                    min_num = right-left+1  ;      
                } 
                tmp-=nums[left] ;
                left++ ;
                continue ;
            }
            right++ ;
            tmp+=nums[right] ;
        }   
        if(flag == 1) return 0 ;
        return min_num ;
    }
};

int main() {
    Solution ss ;
    int s ;
    cin >>  s ;
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) break ;
        ls.push_back(a) ;
    }
    cout << ss.minSubArrayLen(s, ls) << endl ;
    return 0;
}

