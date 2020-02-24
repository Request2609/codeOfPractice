#include <iostream>
#include <vector>
using namespace std ;

class Solution {
public:
    int InversePairs(vector<int> data) {
        int len = data.size() ;
        if(len <= 1) {
            
        }
    }
    //求逆序对
    int mergeSort(vector<int>&ls, int start, int end) {
        if(start == end) {
            return 0 ;
        }
        int mid = (start+end)/2  ;
        int left_count = mergeSort(ls, start, mid) ;
        int right_count = mergeSort(ls, mid+1, end) ;
        int i= mid, j=end ;
        vector<int>tmp = ls ;
        int copy = end-start ;
        int count =  0 ;
        while(i>=start && j>=mid+1) {
            if(ls[i] > ls[j]) {
                tmp[copy--] =  ls[i--] ;
                count+=j-mid ;
                if(count > 1000000007) {
                    count%=1000000007 ;
                }
            }
            else {
                tmp[copy--] =  ls[j--] ;
            }
        }
        while(i>=start) {
            tmp[copy--] = ls[i--] ;
        }
        while(j>=mid+1) {
            tmp[copy--] = ls[j--] ;
        }
        i = 0 ;
        while(start <= end) {
            ls[start++] = tmp[i++] ;
        }
        return left_count+right_count ;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

