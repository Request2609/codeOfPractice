#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int> > FindContinuousSequence(int sum) {
        std::vector<std::vector<int>> ls ;
        int num = 1 ;
        int tmp = sum/num ;
        int k = 1 ;
        while(1){
            num = k*2+1 ;
            k++ ;
            if(sum%num) {
               continue ; 
            }
            tmp = sum/num ;
            std::cout << tmp << std::endl ;
            if(num/2 > tmp) {
                break ;
            }
            std::vector<int>cur ;
            for(int i=tmp-num/2; i<=tmp+num/2; i++) {
                cur.push_back(i) ;
            }
            ls.push_back(cur) ;
        }
        for(auto s : ls) {
            for(int i=0; i<(int)s.size();i++) {
                std::cout << s[i] <<"  " ;
            }
            std::cout << std::endl ;
        }
        return ls ;
    }
    //正解
    //根据等差数列求和公式
    //(high+low)(high-low+1)/2 
    std::vector<std::vector<int> > FindContinuousSequence1(int sum) {
        std::vector<std::vector<int>>ls ;
        int high = 2 ;
        int low = 1 ;
        int cur = 0 ;
        while(low<(sum+1)/2 && high<sum+1) {
            cur = (high+low)*(high-low+1)/2 ;
            if(cur > sum) {
                low++ ;
            }
            if(cur == sum) {
                std::vector<int> ires ;
                for(int i=low; i<=high; i++) {
                    ires.push_back(i) ;
                }
                ls.push_back(ires) ;
                low++ ;
            }
            if(cur < sum) {
                high++ ;
            }
        }
        for(auto s : ls) {
            for(int i=0; i<(int)s.size();i++) {
                std::cout << s[i] <<"  " ;
            }
            std::cout << std::endl ;
        }

        return ls ;
    }
};
int main()
{
    Solution ss ;
    ss.FindContinuousSequence1(100) ;
    return 0;
}

