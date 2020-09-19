#include <iostream>
using namespace std  ;

int main()
{
    int f[1001] ;
    int g[1001] ;
    int a[1001] ;
    int num = 10 ;

    for(int i=0; i<num; i++) {
        cin >> a[i] ;
    }

    for(int i=0; i<num; i++) {
        f[i] = g[i] = a[i] ;
        if (i>0) {
            f[i] = max(f[i], g[i-1]*a[i]) ;
            g[i] = min(f[i-1]*a[i], g[i]);
        }
    }
    int m = -1 ;
    for(int i=0; i<num; i++) {
        if(f[i] > m) {
            m = f[i] ;
        }
    }
    cout << m << endl ;
}

