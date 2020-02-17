#include <iostream>
#include <vector>
using namespace std ;
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string>ls ;
        if(str.empty()) return ls ;
        getRes(ls, str, 0) ;             
        return ls ;
    }
    //不去重复元素
    void getRes(vector<string>&ls, string s, int index) {
        int len = s.size() ;
        if(index >= len) {
            ls.push_back(s) ;
            return ;
        }
        for(int i=index; i<len; i++) {
            if(s[i] == s[index]) continue ;
            swap(s[i], s[index]) ;
            getRes(ls, s, index+1) ;
            swap(s[i], s[index]) ;
        }
    }

    void swap(char& s, char& s1) {
        char c = move(s) ;
        s = move(s1) ;
        s1 = move(c) ; 
    }
};
int main()
{
    Solution ss ;
    string s ;
    cin >> s ;
    auto ls = ss.Permutation(s) ;
    for(string s : ls) {
        cout << s << endl ;
    }
    return 0;
}

