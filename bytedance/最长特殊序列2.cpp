#include <iostream>
#include <vector>
using namespace std ;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int len = strs.size() ;
        if (len == 0) {
            return -1 ;
        }
        string tmp = strs[0] ;
        int size = tmp.size() ;
        int flag = 0 ;
        for(int i=1; i<len; i++) {
            auto t = strs[i].size() ;
            if (size != (int)t) {
                flag = 1 ;
                if (size < (int)t) {
                    size = strs[i].size();
                    tmp = strs[i] ;
                }
            }
        }
        if (flag == 1) {
            return size ;
        }
        for(int i=1; i<len; i++) {
            if(strs[i] != strs[i-1]) {
                return 3 ;
            }
        }
        return -1 ;
    }
};

bool cmp(string& s1,string& s2){
    if(s1.length()!=s2.length())
        return s1.length()>s2.length();
    return s1<s2;
}
//正解
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),cmp);
        for(int i = 0;i<strs.size();i++){
            if(i+1<strs.size()&&strs[i+1]==strs[i])
                continue;
            if(i>0&&strs[i-1]==strs[i])
                continue;
            bool sat = true;
            for(int j = 0;j<i;j++){
                if(j>0&&strs[j]==strs[j-1])
                    continue;
                if(strs[j].length()==strs[i].length())
                    break;
                int p = 0;
                int q = 0;
                while(q<strs[j].length()&&p<strs[i].length()){
                    if(strs[j][q]==strs[i][p]){
                        p++;
                    }
                    q++;
                }
                if(p==strs[i].length()){
                    sat = false;
                    break;
                }
            }
            if(sat)
                return strs[i].length();
        }
        return -1;
    }
};
int main() {
    vector<string>ls ;
    while(1) {
        string tmp ;
        cin >> tmp ;
        if (tmp == "-1") {
            break;
        }
        ls.push_back(tmp) ;
    }
    Solution ss ;
    cout << ss.findLUSlength(ls) << endl ;
    return 0;
}

