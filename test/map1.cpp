#include <iostream>
#include <map>
using namespace std ;

int main()
{
    map<string, string>ls ;
    while(1) {
        string key;
        string value ;
        cin >> key >> value ;
        if(key == "-1") break ;
        ls.insert({key, value}) ;
    }
    find("hello", ls)  ;  
    std::cout << "Hello world" << std::endl;
    return 0;
}

