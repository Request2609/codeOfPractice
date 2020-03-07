#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>>ls ;
        std::vector<int>tmp ;
        if(candidates.empty()) return ls ;
        sort(candidates.begin(), candidates.end()) ;
        getRes(ls, candidates, tmp, target, 0) ;
        return ls ;
    }
    void getRes(std::vector<std::vector<int>>&ls, std::vector<int>can, std::vector<int>tmp, int target, int index) {
        if(target<=0) {
            if(target==0) {
                ls.push_back(tmp) ;
            }
            return ;
        }
        int len = can.size() ;
        for(int i=index; i<len; i++) {
            if(can[i] > target) {
                return ;
            }
            //去除重复的
            if(i>index&&can[i]==can[i-1]) continue ;
            tmp.push_back(can[i]) ;
            getRes(ls, can, tmp, target-can[i], i+1) ;
            tmp.pop_back() ;
        }
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
    int target ;
    std::cin >> target ;
    auto lis = ss.combinationSum2(ls, target) ;
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

