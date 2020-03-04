#include <iostream>
#include <vector>
#include <math.h>
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(numRows == 1) return s ;
        std::vector<std::string>row(min(numRows, int(s.size()))) ;
        int curRow = 0 ;
        bool goDown = false ;
        for(char c:s) {
            row[curRow]+=c ;
            //当前curRow为0或者numRows-1时，箭头反向转折
            if(curRow==0||curRow==numRows-1) { 
                goDown = !goDown ;
            }
            //z字形打印组合
            curRow += goDown?1:-1 ;
        }
        std::string ret ;
        for(auto c:row) {
            ret+=c ;
        }
        return ret ;
    }

    int min(int num1, int num2) {
        return num1>num2?num1:num2 ;
    }
};
int main() {
    Solution ss ;
    std::string s ;
    std::cin >> s ;
    int num ;
    std::cin >>num ;
    std::cout << ss.convert(s, num) << std::endl;
    return 0;
}

