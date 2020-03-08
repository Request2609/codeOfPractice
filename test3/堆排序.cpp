#include <iostream>
#include <vector>

void swap(int& a, int& b) {
    int tmp = std::move(a) ;
    a = std::move(b);
    b = std::move(tmp) ;
}

//将堆顶元素从堆中取出来，然后放到有序区
void max_heap(std::vector<int>&ls, int start, int end) {
    //最后一个父亲节点
    int dad = start ;
    //儿子节点
    int son = dad*2+1 ;
    
    while(son <= end) {
        //好友左右孩子，找出最大节点
        if(son+1<=end && ls[son]<ls[son+1]) {
            son++ ;
        }
        if(ls[dad]>ls[son]) { //父亲节点大于孩子节点  直接跳出
            return ;
        }
        //否则　交换父子节点
        swap(ls[son], ls[dad]) ;
        //将父亲节点
        dad = son ;
        son = dad*2+1 ;
    }
}


void heap_sort(std::vector<int>&ls) {
    int len = ls.size() ;
    //从最后一个父亲节点开始调整，
    for(int i=len/2-1; i>=0; i--) {
        max_heap(ls, i, len-1) ;
    }
    //先将第一个元素和已经排好的元素前一位作交换，再从新调整的元素之前的元素，知道排序完成
    for(int i=len-1; i>0; i--) {
        swap(ls[0], ls[i]) ;
        max_heap(ls, 0, i-1) ;
    }
}

int main() {

    std::vector<int>ls{3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6} ;
    heap_sort(ls) ;
    for(int i=0; i<(int)ls.size(); i++) {
        std::cout << ls[i] << " " ;
    }
    std::cout << std::endl ;

    return 0;
}

