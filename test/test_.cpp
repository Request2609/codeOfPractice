#include <iostream>
#include <map>
using namespace std ;
int main()
{
    multimap<int, string>ls ;
    ls.insert({1, "hello"}) ;
    ls.insert({1, "hello"}) ;
    ls.insert({1, "hello"}) ;
    ls.insert({1, "hello"}) ;
    for(auto s :ls) {
        cout << s.first <<"   " << s.second << endl ;
    }
    return 0;
}

