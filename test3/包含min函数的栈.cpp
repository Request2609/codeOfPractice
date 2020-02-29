#include <iostream>
#include <stack>
#include <vector>
using namespace std ;

class Solution {
public:
    vector<int>st ;
    int min_num = INT32_MAX;
    void push(int value) {
        if(value<min_num) {
            min_num = value ;
        }
        st.push_back(value) ;   
    }

    void pop() {
        int num = st[st.size()-1] ;
        st.pop_back() ;
        if(num == min_num) {
            min_num = INT32_MAX ;
            for(auto s:st) {
                if(s < min_num) {
                    min_num = s ;
                }
            }
        }
    }

    int top() {
        return st[st.size()-1] ;
    }
    int min() {
        return min_num;
    }
};

