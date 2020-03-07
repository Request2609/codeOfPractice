#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>>ls ;
        std::vector<int>tmp ;
        sort(candidates.begin(), candidates.end()) ;
        find(ls, candidates, tmp, target, 0) ;
        return ls ;
    }
    //递归
    int find(std::vector<std::vector<int>>&ls, std::vector<int>stmp, std::vector<int>tmp, int target, int index) {
        if(target >= 0) {
            if(target == 0) {
                ls.push_back(tmp) ;
                return 1 ;
            }
            return 0;
        }
        int len = stmp.size() ;
        for(int i=index; i<len; i++) {
            auto tmp_ = tmp ;
            tmp_.push_back(stmp[i]) ;
            find(ls, stmp, tmp_, target-stmp[i], i) ;
        }
        return 1 ;
    }
    
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

