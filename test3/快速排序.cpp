#include <iostream>
#include <vector>

void swap(int& a, int& b) {
    int tmp = std::move(a) ;
    a = std::move(b) ;
    b = std::move(tmp) ;
}

void quick_sort(std::vector<int>&ls, int start, int end) {
    if(start >= end) {
        return ;
    }
    int left = start ;
    int right = end ;
    //选取最后一个作为基准数
    int mid = ls[end] ;
    while(left<right) {
        while(ls[left]<mid&&left<right) {
            left++ ;
        } 
        while(ls[right]>=mid&&right>left) {
            right-- ;
        }
        swap(ls[left], ls[right]) ;
    }
    if(ls[left] >= ls[right]) {
        swap(ls[left], ls[right]) ;
    }
    else {
        left++ ;
    }
    quick_sort(ls, start, left-1) ;
    quick_sort(ls, left+1, end) ;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

