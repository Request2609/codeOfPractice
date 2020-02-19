#include <iostream>
#include <vector>
using namespace std ;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum = 0 ;
        int tmp = INT32_MIN ;
        int len = array.size() ;
        for(int i=0; i<len; i++) {
            sum+=array[i] ;
            if(sum>tmp) {
                tmp = sum ;
            }
            if(sum<0) {
                if(sum > tmp) {
                    tmp = sum ;
                }
                sum = 0 ;
            }
        }
        return tmp ;
    }
};
int main() {
    Solution ss ;
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) break ;
        ls.push_back(a) ;
    }
    cout << ss.FindGreatestSumOfSubArray(ls) << endl ;
    return 0;
}

