#include <iostream>
#include <string.h>
#include <vector>
class Solution {
public:
    std::string ReverseSentence(std::string str) {
        int len = str.size() ;
        std::vector<std::string>ls ;
        std::string s ;
        for(int i=0; i<len; i++) {
            if(str[i] == ' ') {
                ls.push_back(s) ;
                s.clear() ;
                continue ;
            }
            s+=str[i] ;
        }
        ls.push_back(s) ;
        s.clear() ;
        len = ls.size() ;
        for(auto t=ls.rbegin(); t!=ls.rend(); t++) {
            s+=*t ;
            if(t+1!=ls.rend()) {
                s+=' ' ;
            }
        }
        return s ;
    }
};

int main() {
    Solution ss ;
    std::string data ;
    getline(std::cin, data) ;
    ss.ReverseSentence(data) ;
    return 0;
}

