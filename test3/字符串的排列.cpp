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
    bool isIn(const string s, vector<string>ls) {
        for(auto res:ls) {
            if(s == res) return false ;
        }
        return true ;
    }

    void getRes(vector<string>&ls, string s, int index) {
        int len = s.size() ;
        if(index >= len) {
            ls.push_back(s) ;
            return ;
        }

        for(int i=index; i<len; i++) {
            if(check(s, index, i)) {
                swap(s[i], s[index]) ;
                getRes(ls, s, index+1) ;
                swap(s[i], s[index]) ;
            }
        }
    }
    bool check(string s, int start, int end) {
        if(end > start) {
            for(int j=start; j<end; j++) {
                if(s[j] == s[end]) {
                    return false ;
                }
            }
        }
        return true ;
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
    cout << ls.size()<< endl ;
    for(string s : ls) {
        cout << s << endl ;
    }
    return 0;
}

