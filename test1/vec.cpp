#include <iostream>
#include <vector>
using namespace std ;
int main()
{
    vector<int>ls ;
    ls.push_back(2) ;
    ls.push_back(2) ;
    ls.push_back(2) ;
    ls.push_back(2) ;
    ls.push_back(2) ;
    ls.push_back(2) ;
    ls.push_back(4) ;
    ls.push_back(3) ;
    for(auto i=ls.begin(); i!=ls.end(); i++) {
        if(*i == 2) {
            ls.erase(i) ; 
            i-- ;
        }
    }
    cout << ls.size() << endl ;
    return 0 ;
}

