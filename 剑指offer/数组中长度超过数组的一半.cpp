#include <iostream>
#include <map>
#include <vector>
using namespace std ;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(!numbers.size()) return 0 ;
        if(numbers.size() == 1) return 1 ;
        map<int, int> mp ;
        int counts = INT32_MIN ;
        int len  = numbers.size() ;
        int mem = 0 ;
        for(int i=0; i<len; i++) { 
            if(mp.find(numbers[i]) == mp.end()) {
                mp[numbers[i]] = 1 ;
            }
            else {
                int num = ++mp[numbers[i]] ;
                if(num > counts) {
                    counts = num ;
                    mem = numbers[i] ;
                }
            }
        }
        cout << mp.size() << endl ;
        if(mp[mem] <= (int)numbers.size()/2) {
            return 0 ;
        }
        return mem ;
    }
};
int main()
{
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) break ;
        ls.push_back(a) ;
    }
    Solution ss ;
    cout << ss.MoreThanHalfNum_Solution(ls) << endl ;
    return 0;
}

