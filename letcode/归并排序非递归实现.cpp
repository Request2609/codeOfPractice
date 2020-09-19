#include <iostream>
#include <vector>
//归并排序递归实现
class Merge{
public :
    //归并排序递归实现
    void sort(std::vector<int>ls, int left, int right, std::vector<int>&tmp) {
        int mid = (left+right)/2 ;
        if(left<right) {
            sort(ls, left, mid, tmp) ;
            sort(ls, mid+1, right, tmp) ;
            mergePass(ls, left, mid, right, tmp) ;
        }
    }

    //非递归实现
    void sort1(std::vector<int>ls, int left, int right, std::vector<int>&tmp) {
        int len = ls.size() ;
        int size = 1 ;
        while(size<len) {
            for(int j=0; j<len; j+=size*2) {
                //左边界的长度
                left = j ;
                //右边界的长度
                right = j+2*len-1 ;
                //中间段的长度
                int mid = j+len-1 ;
                //当high的值大于总数组长度的时候，将high设置成最大下表
                if(right>len-1) {
                    right = len-1; 
                }
                //合并的函数
                mergePass(ls, left, mid, right, tmp) ;
            }
            size*=2 ;
        }
    }
    
    //将子数组归并
    void mergePass(std::vector<int>ls, int left, int mid, int right, std::vector<int>&tmp) {
        int i = left ;
        int j = mid+1 ;
        int t = 0 ;
        while(i<=mid&&j<=right) {
            if(ls[i]>ls[j]) {
                tmp[t++] = ls[i++] ;
            }
            else {
                tmp[t++] = ls[j++] ;
            }
        }
        while(i<=mid) {
            tmp[t++] = ls[i++] ;
        }
        while(j<=right) {
            tmp[t++] = ls[j++] ;
        }
        t = 0 ;
        while(t<=right) {
            ls[left++] = tmp[t++] ;
        }
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

