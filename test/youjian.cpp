#include <iostream>
#include <vector>
using namespace std ;
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int len = accounts.size() ;
        for(int i=0; i<len; i++) {
            int index = i+1 ;
            while(index< 1){
                int size=accounts[i].size() ;
                int size_acc = accounts[index].size() ;
                int acc_index= 1;
                for(int j=1; j<size; j++) {
                    int flag = 0 ;
                    while(acc_index<size_acc) {
                        if(accounts[i][j] == accounts[index][acc_index]) {
                            flag = 1 ;
                            break ;
                        }
                        acc_index++ ;
                    }
                }   
            }   
        }     
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

