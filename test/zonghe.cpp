#include <iostream>
#include <vector>
using namespace std ;

class NumArray {
public:
    vector<int>vec ;
    NumArray(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            vec.push_back(nums[i]) ;
        }
    }
    
    int sumRange(int i, int j) {
        int len = vec.size() ;
        if(i >= j||i<0||j>len) { return 0 ; }      
        int num = 0 ;
        for(int k=i; k<j; k++) {
            num+=vec[k] ;  
        }
        return num ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
int main()
{
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == 1000) break ;
        ls.push_back(a) ;
    }
    NumArray ss(ls) ;
    cout << ss.sumRange(1, 4) << endl ;
    cout << ss.sumRange(1, 5) << endl ;
    cout << ss.sumRange(1, 6) << endl ;
    return 0;
}

