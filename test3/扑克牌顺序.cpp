#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool IsContinuous(std::vector<int> numbers) {
	
        sort(numbers.begin(), numbers.end()) ;
        int len = numbers.size() ;
	if(len == 0) return false ;        
	int count = 0 ;
        for(int i=0; i<len-1; i++) {
            if(numbers[i] == 0) {
                count++ ;
                continue ;
            }
            if(numbers[i] != 0 && numbers[i] == numbers[i+1]) return false ;
            else if(numbers[i+1]-numbers[i] != 1){
                if(count > 0)
                    count-=(numbers[i+1]-numbers[i]-1) ;
                else 
                    return false;
            }
        }
        if(count <0) return false ;
        return true ;
    }
};

int main()
{
    std::vector<int>ls ;
    while(1) {
        int a ;
        std::cin>> a ;
        if(a == -1) break ;
        ls.push_back(a) ;
    }
    Solution ss ;
    std::cout << ss.IsContinuous(ls) << std::endl;
    return 0;
}

