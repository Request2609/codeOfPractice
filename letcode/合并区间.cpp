#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    static bool cmp(std::vector<int>num1, std::vector<int>num2) {
        return num1[1]<num2[1] ;
    }
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>>ls ;
        int len = intervals.size() ;
        if(len == 0) return ls ;
        sort(intervals.begin(), intervals.end(), cmp) ;
        for(int i=0; i<len-1; i++) {
            int size = intervals[i+1].size() ;
            int preend = intervals[i][size-1] ;
            int nextstart = intervals[i+1][0] ;
            if(preend>=nextstart-1) {
                //要是当前区间的最大大于下一个区间的最小，需要合并
                intervals[i+1][0]=intervals[i][0]>=intervals[i+1][0]?intervals[i+1][0]:intervals[i][0] ;
                //重新设置当前区间最小值为特殊值
                intervals[i][0]=INT32_MIN  ;
            }
        }
        for(int i=0; i<len;  i++) {
            if(intervals[i][0] == INT32_MIN) continue ;
            ls.push_back(intervals[i]) ;  
        }
        return ls ;
    }
    //正确解法
    std::vector<std::vector<int>> merge1(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size() ;
        std::vector<std::vector<int>> res ;
        std::vector<int>starts, ends ;
        for(int i=0; i<n; ++i) {
           starts.push_back(intervals[i][0]) ;
           ends.push_back(intervals[i][1]) ;
        }
        sort(starts.begin(), starts.end()) ;
        sort(ends.begin(), ends.end()) ;
        for(int i=0, j=0; i<n; i++) {
            if(i != n-1 ||starts[i+1]>ends[i]) {
                res.push_back({starts[j], ends[i]}) ;
                j = i+1 ;
            }
        }   
        return res ;
    }
};

int main()
{
    Solution ss ;
    std::vector<std::vector<int>>res ;
    int n ;
    int m ;
    std::cin >> n ;
    while(n) {
        m = 2 ;
        std::vector<int>ls ;
        while(m) {
            int a ;
            std::cin >> a ;
            ls.push_back(a) ;
            m-- ;
        }
        res.push_back(ls) ;
        n-- ;
    }
    std::cout << "输入完程!" << std::endl ;
    auto sss = ss.merge(res) ; 
    int len = sss.size() ;
    for(int i=0; i<len; i++) {
        int size = sss[i].size() ;
        for(int j=0; j<size; j++) {
            std::cout << sss[i][j] << " " ;
        }
        std::cout << std::endl ;
    }

    return 0;
}

