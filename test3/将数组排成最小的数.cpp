#include <iostream>
#include <vector>
using namespace std ;
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string>ls ;
        int len = numbers.size() ;
        if(len == 0) return "" ;
        for(int i=0; i<len; i++) {
            ls.push_back(to_string(numbers[i])) ;
        }
        for(int i=0; i<len; i++) {
            int flag =1 ;
            for(int j=0; j<len-1-i; j++) {
                if(ls[j]+ls[j+1] > ls[j+1]+ls[j]) {
                    swap(ls[j], ls[j+1]) ;
                    flag = 0 ;
                }
            }
            if(flag == 1) break ;
        }
        string num = "" ;
        for(int i=0; i<len; i++) {
            num += ls[i] ;
        }
        return num ;
    }
    void swap(string& s1, string&s2) {
        string tmp = move(s1) ;
        s1 = move(s2) ;
        s2 = move(tmp) ;
    }
};
int main()
{
    Solution ss ;
    vector<int>ls ;
    while(1) {
        int a ;
        cin >>a ;
        if(a == -1)break ;
        ls.push_back(a) ;
    }
    cout << ss.PrintMinNumber(ls) << endl ;
    return 0;
}

