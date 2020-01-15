#include <iostream>
#include <sys/time.h>
#include <vector>
using namespace std ;
class Solution {
public:
    //初始化数组
    Solution(vector<int>& nums) {
        srand(time(NULL));
        len = nums.size() ;
        for(int i=0; i<len; i++) {
            num.push_back(nums[i]) ;
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return num ;
    }
    void swap(int& a, int& b) {
        int aaa = move(a) ;
        a = move(b) ;
        b = move(aaa) ;
    }
    int getRes(vector<int>ls, int index) {
        int len = ls.size() ;
        if(index >= len) {
            res.push_back(ls) ;
            return 1;
        }
        for(int i=index; i<len; i++) {
            swap(ls[i], ls[index]) ;
            getRes(ls, index+1) ;
            swap(ls[i], ls[index]) ;
        }
        return 1 ;
    }
    void print() {
        int len = res.size() ;
        for(int i=0; i<len; i++) {
            int s = res[i].size() ;
            for(int k=0; k<s; k++) {
                cout << res[i][k] <<"  ";
            }
            cout << endl ;
        }
    }
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int>ls ;    
        static int kk = getRes(ls, 0) ;
        int index= rand()%len ;
        return res[index] ;
    }   
    static int count ;
    int len ;
    vector<vector<int>> res ;
    vector<int> num ;
};
int main()
{
    vector<int>ls{1,2,3};
    Solution ss(ls) ;
    ss.shuffle() ;
    ss.print() ;
    return 0;
}

