#include <iostream>
#include <vector>
using namespace std ;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res  ;
        res.push_back(vector<int>()) ;
        for(int i=0; i<(int)nums.size(); i++) {
            int all = res.size() ;
            for(int j=0; j<all; j++) {
                auto tmp = res[j] ;
                tmp.push_back(nums[i] ) ;
                res.push_back(tmp) ;
            }
        }
        return res ;
    }
};
int main()
{
    return 0;
}

