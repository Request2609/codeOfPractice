#include <iostream>
#include <string>

class Solution {
public:
    std::string LeftRotateString(std::string str, int n) {
        int size = str.size() ;
        std::string tmp=str ;
        int index = 0 ;
        for(int i=0; i<size; i++) {
            if(i-n<0) {
                n = n%size ;
                index = size+i-n ;
                tmp[index] = str[i] ;
            }      
            else {
                tmp[i-n] = str[i] ;   
            }
        }
        return tmp ;
    }
};

int main() {
    Solution ss ;   
    std::string as ;
    int n = 0 ;
    std::cin >> as ;
    std::cin >> n ;
    std::cout << ss.LeftRotateString(as, n) << std::endl;;
    return 0;
}

