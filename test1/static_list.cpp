#include <iostream>
#include <vector>
using namespace std ;

template<class T>
class List 
{
public:
    List():nextCount(-1) 
    {}
    ~List() 
    {}
    vector<T> ls ;
    int nextCount ;
    
    T getNext() 
    {
        return ls[nextCount] ;
    }

    bool next() 
    {
        nextCount++ ;
        if(nextCount < ls.size()) 
        {
            return true;
        }
        nextCount = -1 ;
        return false ;
    }

    void add(T ob) 
    {
        ls.push_back(ob) ;
    }
      
    bool find(T ob) 
    {
        for(auto iter=ls.begin(); iter != ls.end(); iter++) 
        {
            if(*iter == ob)  
            {
                return true ;
            }
        }
        return false ;
    }

    //将删除所有和ob相同的元素对象
    void remove(T ob) 
    {
        for(auto iter=ls.begin(); iter!=ls.end(); iter++) 
        {
            if(ob == *iter) 
            {
                ls.erase(iter) ;
                iter -- ;
            }
        }   
    }
    size_t size() 
    {
        return ls.size() ;
    }
} ;

//test 
int main()
{
    List<int>ls ;
    ls.add(1) ;
    ls.add(2) ;
    ls.remove(1) ;
    cout << ls.find(2) << endl ;
    ls.add(2) ;
    ls.add(4) ;
    ls.add(5) ;
    ls.add(6) ; 

    cout << "==========================" << endl ;
    while(ls.next()) {
         cout << ls.getNext() << endl ;  
    }
    return 0;
}

