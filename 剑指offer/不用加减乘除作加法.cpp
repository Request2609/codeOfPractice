#include <iostream>
#include <vector>
class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum = 0 ;
        int arr = 0 ;
        while(num2 != 0) {
            sum=num1^num2 ;
            arr = (num1&num2)<<1 ;
            num1 = sum ;
            num2 = arr ;
        }
        return num1 ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

