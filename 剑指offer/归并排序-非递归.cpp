#include <iostream>
#include <vector>
using namespace std ;

class MergeSort {
public :
    void Merge(vector<int>&ls) {
        int len = 1 ;
        int size = ls.size() ;
        while(len <= size) {
            //从一到size/2进行切分
            for(int i=0; i+len <= size; i+=len*2) {
                //计算开始中间和结束的下标
                int low = i , mid=i+len-1, high = i+2*len-1 ;
                if(high > size-1) {
                    high = size-1 ; //整个待排序数组为奇数的情况
                }  
                MergePass(ls, low, mid, high) ;
            }
            len*=2 ;
        }
    }
    
    //将切分的数组进行归并排序，同递归一样
    void MergePass(vector<int>&ls, int low, int mid, int high) {
        vector<int> tmp = ls ;
        int right = mid+1 ;
        int tmpIndex = low ;
        int begin = low ;
        while(low<=mid&&right<=high) {
            if(ls[low] <= ls[right]) {
                tmp[tmpIndex++] = ls[low++] ;
            }
            else {
                tmp[tmpIndex++] = ls[right] ;
            }
        }
        while(low <= mid) {
            tmp[tmpIndex++] = ls[low++] ;
        }
        while(right<=high) {
            tmp[tmpIndex++] = ls[right++] ; 
        }

        while(begin<=high) {
            ls[begin] = tmp[begin] ;
            begin++ ;
        }
    }
} ;

int main()
{
    
    return 0;
}

