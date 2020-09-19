#include <iostream>
#include <vector>

void insert(std::vector<int>&ls) {
    int len = ls.size() ;
    for(int i=1; i<len; i++) {
        if(ls[i-1]>ls[i]) {
            //定义变量存储当前的点
            int tmp = ls[i] ;
            int j = i-1 ;
            while(j>=0&&tmp<ls[j]) {
                ls[j+1] = ls[j] ;
                ls[j] = tmp ;
                j-- ;
            }
        }
    }
}


int main()
{
    std::vector<int>ls{9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6} ;
    insert(ls) ;
    for(int i=0; i<(int)ls.size(); i++) {
        std::cout << ls[i] << " " ;
    }
    std::cout << std::endl ;

    return 0; 
}

