#include <iostream>
#include <vector>
class Solution {
public:
    int GetNumberOfK(std::vector<int> data ,int k) {
        int len = data.size() ;
        if(len == 0) return 0 ;
        int count  = 0 ;
        int flag = 0 ;
        for(int i=0; i<len; i++) {
            if(data[i] == k) {
                flag = 1 ;
                count++ ;
            }
            if(data[i] != k && flag == 1) break ;
        }
        return count ;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

