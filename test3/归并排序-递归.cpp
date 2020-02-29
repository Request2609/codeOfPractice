#include <iostream>
#include <vector>

using namespace std ;
//归并排序递归实现

class Merge {
public :
    //将大的数组分成若干个小的分数组
    void sort(vector<int>&ls, int left, int right, vector<int>&tmp) {
        int mid = (left+right)/2 ;
        if(left < right) {
            sort(ls, left, mid, tmp); //左边归并排序，使得左边有序
            sort(ls, mid+1, right, tmp) ;
            MergePass(ls, left, mid, right, tmp) ; //合并左右有序序列
        }
    }
    //合并
    void MergePass(vector<int>&ls, int left, int mid, int right, vector<int>&temp) {
        int i=left ; //左序列指针
        int j = mid+1 ;//右序列指针
        int t = 0 ; //临时数组指针
        //拆分成两个相邻的有序子序列
        while(i<=mid&&j<=right) { //相当于合并有序链表，两个指针同时移动
            if(ls[i]<=ls[j]) {
                temp[t++] = ls[i++] ;
            }
            else {
                temp[t++] = ls[j++] ;
            }           
        }
        //将剩余的左边元素填充到tmp中
        while(i<=mid) {
            temp[t++] = ls[i++] ;
        }
        //将右边的元素填充到临时数组中
        while(j<=right) {
            temp[t++] = ls[j++] ;
        }

        t = 0 ;
        //将数据从临时数组拷贝到原来的数组
        while(left <= right) {
            ls[left++] = temp[t++] ;
        }
    }
} ;
int main() {
    vector<int>ls ;
    Merge mer ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) break ;
        ls.push_back(a) ;
    }   
    vector<int>tmp = ls;
    tmp.reserve(ls.size()) ;
    mer.sort(ls, 0, ls.size()-1, tmp) ;
    int len = ls.size() ;
    for(int i=0; i<len; i++) {
        cout << ls[i] <<"  ";
    }
    cout << endl ;
}
