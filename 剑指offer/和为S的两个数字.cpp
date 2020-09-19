#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> FindNumbersWithSum(std::vector<int> array,int sum) {
        int left= 0 ;
        int len = array.size() ;
        int right = len-1 ;
        int cur = 0 ;
        int mins = INT32_MAX ;
        cur = array[left]+array[right] ;
        std::vector<int>ls ;
        int num1 = 0 ;
        int num2 = 0 ;
        while(right>left) {
            if(cur > sum) {
                right-- ;
                cur = array[left]+array[right] ;
            }
            if(cur<sum) {
                left++ ;
                cur = array[left]+array[right] ;
            }   
            if(cur == sum) {
                if(mins > array[left]*array[right]) {
                    num1 = array[left] ;
                    num2 = array[right] ;
                    break ;
                }
                left++ ;
                cur = array[left]+array[right] ;
            }
        }
        ls.push_back(num1) ;
        ls.push_back(num2) ;
        return ls ;
    }
};

int main()
{
    Solution ss ;
    std::vector<int>ls{5,6,7,8,9,10} ;
    auto aa = ss.FindNumbersWithSum(ls, 13) ;
    if(!aa.empty())
        std::cout << aa.size() <<"    " << aa[0] << "     " << aa[1] << std::endl ;
    return 0;
}

