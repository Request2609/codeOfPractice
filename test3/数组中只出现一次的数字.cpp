#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    void FindNumsAppearOnce(std::vector<int> data,int* num1,int *num2) {
        int len = data.size() ;
        if(len == 0) return ;
        std::map<int, int>ls ;
        for(int i=0; i<len; i++) {
            if(ls.find(data[i]) == ls.end()) {
                ls[data[i]] = 1 ;   
            }
            else {
                ls[data[i]]++ ;
            }
        }
        int flag = 0 ;
        for(auto s : ls) {
            if(s.second == 1 && flag == 1) {
                *num2 = s.first ;   
                flag = 1 ;
            }       
            if(s.second == 1 && flag == 0) {
                *num1 = s.first ;
                flag = 1 ;
            }
        }
    }
};
int main()
{
    Solution ss ;
    int a = 0 ,b = 0;
    std::vector<int>ls{2,4,3,6,3,2,5,5} ;
    ss.FindNumsAppearOnce(ls, &a, &b) ;
    std::cout << a << "    " << b << std::endl ;
    return 0;
}

