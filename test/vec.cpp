#include <iostream>
#include <vector>
using namespace std ;
int main()
{
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) {
            break;
        }
        ls.push_back(a) ;
    }
    cout << ls.size() << "      " << ls[ls.size()-1]<< endl ;
    ls.pop_back() ;
    ls.pop_back() ;
    ls.pop_back() ;
    ls.pop_back() ;
    cout << ls.size() << "      " << endl ;
    return 0;
}

