#include <iostream>
#include <vector>

using namespace std ;

class Array {

public :
    static vector<vector<int>>ls ;
    static void createArray(int length) {
        srand((int)time(NULL)) ;
        vector<int>tmp ;
        for(int i=0; i<length; i++) {
            int a = rand() ;
            tmp.push_back(a) ;
        }
    }
    static void divideArray(vector<int>s, int num) {
        int len=s.size() ;
        int counts = len/num ;
        int index= 0 ;
        if(counts*num < len) {
            index = counts+num ; //记录剩余的数组开始位置
        }
        vector<int>tmp ;
        tmp.push_back(s[0]) ;
        int i= 1;
        while(i < len) {
            if(i%counts == 0) {
                 vector<int>stmp;
                 ls.push_back(tmp) ; 
                 tmp.clear() ;
            }
            if(i == index) {
                for(int k=i; k<len; k++) {
                    tmp.push_back(s[i]) ;
                }
                break ;
            }
            tmp.push_back(s[i]) ;
        }
    }
    static void newArray(vector<int>s, int num) {
        int k = 0 ;
        for(int i=0; i<num; i++) {
            int size = ls[i].size() ;
            for(k=0;k<size; k++) {
                s.push_back(ls[i][k]) ;
            }
        }
    }
};

class Merge {
public :
    vector<int> temp ;
    Merge(vector<int>ls) {
        temp = ls ;
    }
    void sort(vector<int>a) {
        sort(a, 0, a.size()-1) ;
    }
    void sort(vector<int>a, int low, int high){
        if(low >= high) {
            return  ;
        }
        int mid = low+(high-low)/2 ;
        sort(a, low, mid) ;
        sort(a, mid+1, high) ;
        merge(a, low, mid, high) ;
    }
    void merge(vector<int>a, int low, int mid, int high) {
        int i= low ;
        int j = mid+1 ;
        int size= a.size() ;
        for(int k=low; k<high; k++) {
            temp.push_back(a[k]) ;
        }
        for(int k=low; k<=high;k++) {
            if(i>mid) a[k] = temp[j++] ;
            else if(j>high) a[k] = temp[i++] ;
            else if(temp[j] < temp[i]) a[k] = temp[j++] ;
            else a[k] = temp[i++] ;
        }
    }
} ;
int main() {
    
    return 0;
}

