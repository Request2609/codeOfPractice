#include <iostream>
#include <vector>
std::vector<std::vector<int>>tmp ;
void getJshu(std::vector<int>&ls) {
    for(int i=1; i<36; i+=2) {
        if(i%2) {
            ls.push_back(i) ;
        }
    }
}

int func(int start, int num, int count,
         const std::vector<int>&ls) {
    if(count > 9||num<0) {
        return 1;
    }     
    if(count == 9 && num == 0) {
        tmp.push_back(ls) ;
    }
    func(ls[start], num-ls[start], count++, ls) ;
    start++ ;
    func(ls[start], num-ls[start], count++, ls) ;
}

int main()
{
    std::vector<int>ls ;
    getJshu(ls) ;
    func(0, 36, 0, ls) ;
    return 0;
}

