#include <iostream>
#include <set>

using namespace std ;

int main(){
    set<string>ls ;
    ls.insert("b") ;
    ls.insert("c") ;
    ls.insert("a") ;
    ls.insert("b") ;
    ls.insert("e") ;
    for(auto s:ls) {
        cout << s << endl ;
    }
    return 0;
}

