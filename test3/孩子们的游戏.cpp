#include <iostream>
#include <vector>
class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m) {
        if(n == 0 && m == 0)  return -1 ;
        std::vector<int>ls ;
        std::vector<int>copy ;
        for(unsigned int i=0; i<n; i++) {
            ls.push_back(i) ;
        }
        while(ls.size() != 1) {
            int len = ls.size() ;
            int flag = m%len ;
            //要是为0的话，就删除该数
            if(flag ==0) {
                for(int i =0; i<len-1; i++)
                    copy.push_back(ls[i]) ;
            }
            //要是不为0，就删除下标为flag-1的元素
            else {
                for(int i=flag; i<len; i++) {
                    copy.push_back(ls[i]) ;
                }
                for(int i=0; i<flag-1; i++) {
                    copy.push_back(ls[i]) ;
                }
            }
            ls.clear() ;
            ls = copy ;
            copy.clear() ;
        }
        return ls[0] ;
    }
};
int main()
{
    Solution ss ;
    int n,m ;
    std::cin >> n >> m ;
    std::cout << ss.LastRemaining_Solution(n, m) << std::endl ;
    return 0;
}

