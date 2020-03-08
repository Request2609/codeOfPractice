#include <iostream>
#include <vector>
class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>>ls(n, std::vector<int>(m, 0)) ;
        int col = 0 ;
        int row = 0 ;
        ls[row][col] = 1 ;
        int maxs = ls[row][col] ;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(j==0&&i==0) {
                    std::cout << ls[i][j] << " " ;
                    continue ;
                }
                if(i>0) {
                    ls[i][j]+=ls[i-1][j] ;
                }
                if(j>0) {
                    ls[i][j]+=ls[i][j-1] ;
                }
                if(i==n-1&&j==m-1) {
                    maxs = ls[i][j] ;
                }
                std::cout << ls[i][j] << " " ;
            }   
            std::cout << std::endl ;
        }
        return maxs ;
    }
};

int main() {
    Solution ss ;
    int m,  n ;
    std::cin >> n >> m ;
    std::cout << ss.uniquePaths(m, n) << std::endl ;
    return 0;
}

