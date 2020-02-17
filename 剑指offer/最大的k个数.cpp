#include <iostream>
#include <vector>
using namespace std ;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>ls ;       
        for(int i=0; i<k; i++) {
            ls.push_back(INT32_MAX) ;          
        }
        int index = 0 ;
        int len = input.size() ;
        while(index<len) {
            int index2 = k-1 ;
            int flag = 0 ;
            while(index2) {
                if(index2 == k-1 && input[index] > ls[index2]) {
                    break ;
                }
                if(ls[index2]>input[index]) {
                    if(index2%2) {
                        index2 = (index2-1)/2 ;
                    }
                    else {
                        index2 = (index2-2)/2 ;
                    }
                }
                else {
                    flag = 1 ;
                    if(index2 != k-1) {
                        ls[index2] = input[index] ;
                    }
                }
                if(flag == 0) {
                    ls[index2] = input[index] ; 
                }
            }
        }
        return ls ;
   }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

