#include <iostream>
#include <vector>
using namespace std ;
class Solution {
public:
    //正解
    int GetUglyNumber_Solution1(int index) {
        if(index<7) return index ;
        int p2=0, p3=0, p5=0  ;
        int newNum = 1 ;
        vector<int>arr ;
        arr.push_back(newNum) ;
        while((int)arr.size() < index) {
            newNum = min(arr[p2]*2, min(arr[p3]*3, arr[p5]*5)) ;
            if(arr[p2]*2 == newNum) p2++ ;
            if(arr[p3]*3 == newNum) p3++ ;
            if(arr[p5]*5 == newNum) p5++ ;
            arr.push_back(newNum) ;
        }
        return newNum ;
    }

    int GetUglyNumber_Solution(int index) {
        if(index == 1) return 1 ;
        vector<int>ls ;
        ls.push_back(2) ;
        ls.push_back(3) ;
        ls.push_back(5) ;
        if(index == 4) { return 4 ; }
        int num = 4 ;
        int tmp_index = 0 ;
        int cur_min = ls[tmp_index] ;
        int tmp ;
        int i = tmp_index ;
        while(num!=index) {
            tmp = cur_min*2 ;
            if(cur_min < tmp) {
                tmp_index = i ;
                ls[i] = tmp ;
                cur_min = getMin(ls, i) ;
            }
            num++ ;
        }
        int m = INT32_MIN;
        for(int i=0; i<3; i++) {
            cout << ls[i] << endl ;
            if(m < ls[i]) {
                m = ls[i] ;
            }   
        }
        return m;
    }
    int getMin(vector<int>&ls, int& index) {
        int mins = INT32_MAX ;
        int len = ls.size() ;
        for(int i=0; i<len; i++) {
            if(mins > ls[i]) {
                index = i ;
                mins = ls[i] ;
            }
        }
        return mins ;
    }
};
int main() {
    Solution ss ;
    cout << ss.GetUglyNumber_Solution(4) << endl ;
    return 0;
}

