#include <iostream>
#include <string.h>
#include <math.h>
using namespace std ;
class Solution {
public:
    int mod = pow(10, 9)+7 ;
    int knightDialer(int N) {
        if(N == 1) return 10 ;
        int a[20] ;
        int b[20] ;
        bzero(a, sizeof(a)) ;
        bzero(b, sizeof(b)) ;
        b[0] = 2 ;
        b[1] = 2 ;
        b[2] = 2 ;
        b[3] = 2 ;
        b[4] = 3 ;
        b[5] = 0 ;
        b[6] = 3 ;
        b[7] = 2 ;
        b[8] = 2 ;
        b[9] = 2 ;
        for(int i=2; i<N; i++) {
            getNum(a, b, 1, 6, 8) ;
            getNum(a, b, 2, 7, 9) ;
            getNum(a, b, 3, 4, 8) ;
            getNum(a, b, 4, 3, 9, 0) ;
            getNum(a, b, 6, 0, 1, 7) ;
            getNum(a, b, 7, 2, 6) ;
            getNum(a, b, 8, 1, 3) ;
            getNum(a, b, 9, 2, 4) ;
            getNum(a, b, 0, 4, 6) ;
            a[5] = 0 ;
            for(int k=0; k<10; k++) {
                b[k] = a[k] ;   
            }
        }
        int sum = 0 ;
        for(int i=0; i<10; i++) {
            sum+=b[i] ;   
        }
        return sum ;
    }   

    void getNum(int* dst, int* src, int i, int s1, int s2) {
        dst[i] = (src[s1]+src[s2])%mod ;
    }

    void getNum(int* dst, int*src, int i, int s1, int s2, int s3) {
        dst[i] = (src[s1]+src[s2]+src[s3])%mod ;
    }   
};

int main() {
    Solution ss ;
    int a ;
    cin >> a ;
    cout << ss.knightDialer(a) << endl ;
    return 1 ;
}


