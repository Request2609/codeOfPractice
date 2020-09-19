#include <iostream>
#include <vector>
using namespace std ;
/*
 输入一个整数数组，
 实现一个函数来调整该数组中数字的顺序，
 使得所有的奇数位于数组的前半部分，
 所有的偶数位于数组的后半部分，
 并保证奇数和奇数，
 偶数和偶数之间的相对位置不变
 * */
class Solution {
public:
    //使用双指针，但是相对位置发生了改变
    void reOrderArray(vector<int> &array) {
        int len = array.size() ;              
        int l = 0 ;
        int r = 0 ;
        vector<int>tmp ;
        tmp.reserve(len) ;
        while(r<len) {
            while(array[l]%2) l++;
            r = l+1 ;
            while(array[r]%2==0) r++ ;
            l = r ;
            if(r < len) {
                swap(array[l], array[r]) ;
            }
        }
    }

    //查找加插入排序
    void reOrderArray1(vector<int> &array) {
        int len = array.size() ;
        int j=0 ;
        for(int i=0; i<len; i++) {
            if(array[i]%2 == 1) {
                if(i!=j) {
                    int temp = array[i] ;
                    int k= i ;
                    for(k=i; k>j; k--) {
                        array[k] = array[k-1] ;
                    } 
                    array[k] = temp ;
                }
                j++ ;
            }
        }
    }

    void swap(int& num1, int& num2) {
        int tmp = move(num1) ;
        num1 = move(num2) ;
        num2 = move(tmp) ;
    }
};
int main()
{
    Solution ss ;
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1)break ;
        ls.push_back(a) ;
    }
    ss.reOrderArray(ls) ;
    int len = ls.size() ;
    for(int i=0; i<len; i++) {
        cout << ls[i] << endl ;
    }
    return 0;
}

