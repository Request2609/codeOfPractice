#include <iostream>
#include <vector>
#include <math.h>
int n = 0 ;
int getNum(int num1, int num2) {
    int i = num2 ;
    int count = 0 ;
    while(i) {
        n = i ;
        i/=10 ;
        count++ ;
    }
    num1*=pow(10,count) ;
    num1+=num2 ;
    return num1;
}
void swap(int& num1, int&num2) {
    int tmp = std::move(num1) ;
    num1 = std::move(num2) ;
    num2 = std::move(tmp) ;
}
int getHigh(int num) {
    int n = num ;
    while(num) {
        n = num ;
        num/=10 ;
    }   
    return n ;
}

void func(std::vector<int>&ls) {
    int len = ls.size() ;
    for(int i=0; i<len; i++) {
        int flag = 0 ;
        for(int j=1; j<len-i-1; j++) {
            if(getNum(ls[j], ls[j-1])<getNum(ls[j-1], ls[j])) {
                swap(ls[j-1], ls[j]) ;
                flag =1  ;
            }
        }
        if(flag == 0) break ;
    }   
}

int main()
{
    std::vector<int>ls{1,2,11,10,12} ;
    func(ls) ;
    for(int i=0; i<(int)ls.size(); i++) {
        std:: cout << ls[i] <<"  " ;
    }
    std::cout << std::endl ;

    return 0;
}

