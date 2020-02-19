#include <iostream>
#include <vector>

using namespace std ;
class Solution {
public:
    void adjust(vector<int>&ls, int len, int flag) {
        int index = 0 ;
        cout << len << endl ;
        //重新组堆
        int left = index*2+1 ;
        int right = index*2+2 ;
        //初始化小根堆
        while(right<len) {
            int mins = 0 ;
            mins = ls[left]<ls[right]?left:right ;
            if(ls[index]>mins) {
                swap(ls[index], ls[mins]) ;
            }
            index++ ;
            left = index*2+1 ;
            if(left == len-1) {
                if(ls[left] < ls[index]) {
                    swap(ls[left], ls[index]) ;
                    break ;
                }   
            }
            right = index*2+2 ;
        }
    }
    void sortTree(vector<int>&ls) {
        int len = ls.size() ;
        int tmp =ls[len-1] ;
        for(int i=len-2; i>=0; i--) {
            if(tmp < ls[i]) {
                swap(tmp, ls[i]) ;
            }
        }
        ls[len-1] = tmp ;
    }
    //正解
    vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
        vector<int>ls ;
        if(input.size() == 0) {
            return ls ;
        }
        int len = input.size() ;
        if(k>len) {
            return ls;
        }
        int temp ;
        //冒泡排序
        for(int i=0; i<k; i++) {
            for(int j=i+1; j<len; j++) {
                if(input[i] > input[j]) {
                    temp = input[i] ;
                    input[i] = input[j] ;
                    input[j] = temp ;
                }
            }
            ls.push_back(input[i]) ;
        }
        return ls ;
    }   
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>ls ;
        if((int)input.size() < k) return input ;
        for(int i=0; i<k; i++) {
            ls.push_back(input[i]) ;
        }
        adjust(ls, k, 1) ;
        int len = input.size() ;
        for(int i=k; i<len; i++) {
            //小于最后一个节点
            if(input[i] < ls[k-1]) {
                ls[k-1] = ls[0] ;   
                ls[0] = input[i] ;
                //挑出最大的放到最后
                sortTree(ls);
            }  
        }
        return ls ;
    }
    void swap(int& num1, int& num2) {
        int tmp = move(num1) ;
        num1 = move(num2) ;
        num2 = move(tmp) ;
    }

};
int main()
{
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a < 0) {
            break ;
        }
        ls.push_back(a) ;
    }
    int a ;
    cin >> a ;
    Solution ss ;
    vector<int>aa = ss.GetLeastNumbers_Solution(ls, a) ;
    return 0;
}

