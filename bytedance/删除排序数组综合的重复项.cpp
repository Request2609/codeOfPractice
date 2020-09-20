#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

class Solution{
public :
    int removeDuplicate(vector<int>&nums) {
        int i = 0 ;
        for(auto t : nums) {
            if (i < 2 || t > nums[i-2]) {
                nums[i++] = t ;
            }
        }
        for(int k=0; k<i; k++) {
            cout << nums[k] << endl ;
        } 
        return i ;
    }
};

int main()
{
    vector<int>tmp ;
    while(1) {
        int a ;
        cin >> a ;
        if (a == -1) break ;
        tmp.push_back(a) ;
    }
    Solution ss ;
    cout << ss.removeDuplicate(tmp) << endl ;
    return 0;
}

