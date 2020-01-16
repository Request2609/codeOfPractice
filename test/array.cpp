#include <iostream>
#include <vector>

using namespace std ;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool>tmp ;
        int len = A.size() ;
        int sum = 0 ;
        int count = 0 ;
        for(int i=0; i<len; i++) {
            count = 0 ;
            sum+=sum*2+A[i] ;
            sum%=5 ;
            if(sum) {
                cout << "false" << endl ;
                tmp.push_back(false) ;
            }
            else {
                cout << "true" << endl ;
                tmp.push_back(true) ;
            }
        }
        return tmp ;      
    }

    int getPow(int len) {
        int num = 1 ;
        for(int i=0; i<len; i++) {
            num*=2 ;
        }
        return num ;
    }

};
int main()
{
    Solution ss ;
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) break ;
        ls.push_back(a) ;
    }
    ss.prefixesDivBy5(ls) ;

    return 0;
}

