#include <iostream>
#include <vector>
using namespace std ;

int once_quick_sort(vector<int>&data, int left, int right) {
    //确定一个基准数
    int key = data[left] ;
    while(left < right) {
        while(left < right && key < data[right]) {
            right -- ;
        }
        if(left < right) {
            data[left++] = data[right] ;
        }
        while(left < right&& key>=data[left]) {
            left++ ;
        }
        if(left < right) {
            data[right--] = data[left] ;
        }
    }   
    data[left] = key ;
    return left ;
}

int quick_sort(vector<int>data, int left, int right) {
    if(left >= right) {
        return 1 ;
    }
    int middle = 0 ;
    middle = once_quick_sort(data, left, right) ;
    quick_sort(data, left, middle) ;
    quick_sort(data, middle+1, right) ;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

