#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int mins = INT32_MAX ;
        int len = grid.size() ;       
        if(len == 0) return 0 ;
        for(int i=0; i<len; i++) {
            int size = grid[i].size() ;
            for(int j=0; j<size; j++) {
                if(i==0&&j==0) {
                    mins = grid[i][j] ;
                    std::cout << grid[i][j] << " " ;
                    continue ;
                }
                if(i>0&&j==0) {
                    grid[i][j] += grid[i-1][j] ;       
                }
                if(i==0&&j>0) {
                    grid[i][j] += grid[i][j-1] ;      
                }
                if(i>0&&j>0) {
                    int tmp = grid[i-1][j]>grid[i][j-1]?grid[i][j-1]:grid[i-1][j] ;
                    grid[i][j] += tmp ;
                }
                if(i==len-1&&j==size-1) {
                    mins = grid[i][j] ;
                }
                std::cout << grid[i][j] << " " ;
            }
            std::cout << std::endl ;
        }
        return mins ;
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
        std::cin >> m;
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
    std::cout << ss.minPathSum(res) << std::endl ;
    return 0;
}

