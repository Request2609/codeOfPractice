#include <iostream>
#include <vector>
void insert(std::vector<int>&ls) {
    int len = ls.size() ;
    for(int i=1; i<len; i++) {
        if(ls[i] < ls[i-1]){
            int j = i ;
            int tmp = ls[i] ;
            while(j>0&&tmp<ls[j-1]) {
                ls[j] = ls[j-1] ;
                j-- ;
            }
            ls[j] = tmp ;
        }
    }
}
int main()
{
    std::vector<int>ls{4,5,3,2,1,6,7} ;
    insert(ls) ;
    int len = ls.size() ;
    for(int i=0; i<len; i++) {
        std::cout << ls[i] << std::endl ;
    }
    return 0;
}

