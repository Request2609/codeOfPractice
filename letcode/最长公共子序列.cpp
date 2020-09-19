#include <iostream>
using namespace  std ;

int dp[200][200] ;
int a[2005] ;
int b[2005] ;
int main() {
    string str1 ;
    string str2 ;
    cin >> str1 >> str2 ;
    for(int i=0; i<=(int)str1.size(); i++) {
        dp[i][0] = 0 ;
    }
    for(int j=0; j<=(int)str2.size(); j++) {
        dp[0][j] = 0 ;
    }
    for(int i=1; i<=(int)str1.size(); i++) {
        for(int j=1; j<=(int)str2.size(); j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1 ;
            }else {
                dp[i][j] = dp[i-1][j] > dp[i][j-1]?dp[i-1][j]:dp[i][j-1]; 
            }
        }
    }
    int len1 = str1.size() ;
    int len2 = str2.size() ;
    cout << dp[len1][len2] << endl  ;
    return 0;
}

