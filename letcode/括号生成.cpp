#include <iostream>
#include <vector> 

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string>ls ;
        if(n==0) return ls ;
        std::string track = "" ;
        int index = 0 ;
        backtrack(ls, track, n, index) ;
        return ls ;
    }
    void backtrack(std::vector<std::string>&ls, 
                   std::string track, int n, int index) {
        if(n==0&&index==0) {
            ls.push_back(track) ;
            return ;
        }
        //n-1控制左括号的数量，index控制右括号的数量
        //当左括号增多的时候，track-1，index+1(也就是需要
        //更多的右括号与之相匹配)
        if(n>0) backtrack(ls, track+"(", n-1, index+1) ;
        if(index > 0) backtrack(ls, track+")", n, index-1) ;
    }
};

int main()
{
    return 0;
}

