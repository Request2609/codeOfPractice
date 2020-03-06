#include <iostream>
#include <vector>

void swap(int& i, int& j) {
    int tmp = std::move(i) ;
    i = std::move(j) ;
    j = std::move(tmp) ;
}

int sort(std::vector<int>&ls, int l, int r) {
    //找个基准数字
    int p = ls[l] ;
    int i = l ;
    int j = r ;
    while(i<j) {
        while(i<j&&ls[i]<=p) {
            i++ ;
        }
        while(i<j&&ls[j]>=p) {
            j-- ;
        }
        swap(ls[i], ls[j]) ;
    }
    swap(ls[i], ls[l]) ;
    return i ;
}

void quicksort(std::vector<int>&ls, int l, int r) {
    int index = 0 ;
    while(l<r) {
        index = sort(ls, l, r) ;
        sort(ls, l, index-1) ;
        sort(ls, index+1, r) ;
    }
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

