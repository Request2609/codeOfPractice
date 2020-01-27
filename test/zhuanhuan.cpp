#include <iostream>
#include <vector>
#include <set>
using namespace std ;
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        set<string>res ;
        vector<string>ss ;
        int flag = 0 ;
        for(auto s : S) {
            if(isChar(s)) {
                flag = 1 ;
                break ;
            }
        }
        if(flag == 0) {
            ss.push_back(S) ;
            return ss;
        }
        getRes(res, 0, S) ;
        for(auto s: res) {
            ss.push_back(s) ;
        }
        return ss ;
    }

    void getRes(set<string>& res, int index, string str) {
        int len = str.size() ;
        if(index >= len) {
            return ;
        }
        while(index < len && !isChar(str[index])) index++ ;
        if(index >= len) return  ; 
        res.insert(str) ;
        getRes(res, index+1, str) ;  
        exChange(str[index]) ;
        res.insert(str) ;
        getRes(res, index+1, str) ;
    }

    void exChange(char& c) {
        if(c >= 'a' && c <='z') {
            c -= 32 ;
        }
        else {
            c += 32 ;
        }
    }
    bool isChar(char ch) {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a'&& ch <= 'z') ;  
    }
};

int main() {
    Solution ss ;
    string s ;
    cin >> s ;
    ss.letterCasePermutation(s) ;
    return 0;
}

