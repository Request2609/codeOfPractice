#include <iostream>
#include <string>
#include <map>
using namespace std ;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(!str.size()) {
            return -1 ;
        }
        int len = str.size() ;       
        map<char, pair<int, int>>ls ;
        for(int i=0; i<len; i++) {
            if(ls.find(str[i]) == ls.end()) {
                ls.insert({str[i], {i, 1}}) ;
            }
            else {
                ls[str[i]].second++ ;
            }
        }
        if(ls.empty()) {
            return -1 ;
        }
        int mins = INT32_MAX ;
        for(auto res:ls) {
            if(mins > res.second.first&&res.second.second == 1) {
                mins = res.second.first ;
            }
        }
        return mins ;
    }   
};

int main()
{
    Solution ss ;
    string ch ;
    cin >> ch ;
    cout << ss.FirstNotRepeatingChar(ch) << endl;
    return 0;
}

