#include <iostream>

class Solution {
public:
    int Sum_Solution(int n) {
        int sum=n ;
        bool flag = (sum>0)&&((sum+=Sum_Solution(n-1))>0) ;
        return sum ;
    }   
};

int main()
{
    Solution ss ;
    std::cout << ss.Sum_Solution(10) << std::endl ;
    return 0;
}

