#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

//广度优先搜索
class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::unordered_map<char, std::string> table{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
                {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
                {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
                {'9',"wxyz"}};  
        std::queue<std::string>ls ;
        std::vector<std::string>res ;
        if(!digits.size()) return res ;
        char c = digits[0] ;
        //降低一个数字对应的所有字母全部入队
        for(int i=0; i<(int)table[c].size(); i++) {
            std::string s;
            s += table[c][i] ;
            ls.push(s) ;
        }
        //从第二个数字开始
        int index = 1 ;
        int flag = 0 ;
        int len = digits.size() ;
        //外层队列控制当前数字
        while(index<len) {
            flag = 1 ;
            //当队列不为空，就一直的循环
            int size = ls.size() ;
            while(!ls.empty()&&size) {
                std::string s = ls.front() ;
                //要是队列中的元素长度等于输入的数字长度，作为组合的结果入队
                if(s.size() == digits.size()) {
                    res.push_back(s) ;
                    ls.pop() ;
                    continue ;
                } 
                std::string stmp="" ;
                //当digit中还有元素时
                stmp = table[digits[index]] ;
                //向队列中压入元素
                for(auto c : stmp) {
                    std::string tmp=s ;
                    tmp+=c ;
                    ls.push(tmp) ;
                }
                ls.pop() ;
                size-- ;
            }  
            index++ ;
        }
        while(flag == 1&&!ls.empty()) {
            res.push_back(ls.front()) ;
            ls.pop() ;
        }
        while(flag == 0 && !ls.empty()) {
            res.push_back(ls.front()) ;
            ls.pop() ;
        }
        return res ;
    }
};


int main()
{
    Solution ss ;
    std::string tmp ;
    std::cin >> tmp ;
    auto res = ss.letterCombinations(tmp) ;
    for(int i=0; i<(int)res.size() ; i++) {
        std::cout << res[i] << std::endl ;
    }
    return 0;
}

