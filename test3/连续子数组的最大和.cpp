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
            //获取当前最大累加和
            if(sum>tmp) {
                tmp = sum ;
            }
            if(sum<0) {
                //sum小于0，但是tmp比sum小，tmp重新设置成sum
                if(sum > tmp) {
                    tmp = sum ;
                }
                //设置成0，和之后的元素求和
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

