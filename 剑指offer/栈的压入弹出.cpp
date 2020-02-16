#include <iostream>
#include <vector>
#include <stack>
using namespace std ;

/*
输入两个整数序列，
第一个序列表示栈的压入顺序，
请判断第二个序列是否可能为
该栈的弹出顺序。假设压入栈的
所有数字均不相等。例如序列1,2,
3,4,5是某栈的压入顺序，序列4,5,
3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹
出序列。（注意：这两个序列的长度是相等的）
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() && popV.empty()) return true ;
        stack<int>st1 ;
        int len = pushV.size() ;
        int index1 = 0 ;
        int index2 = 0 ;
        while(index1<len) {
            int tmp = pushV[index1] ;       
            int tmp1 = popV[index2] ;
            if(tmp != tmp1) {
                st1.push(tmp) ;
            }
            else {
                while(!st1.empty()) {
                    index2 ++ ;
                    int tmp = st1.top() ;
                    tmp1 = popV[index2] ;
                    if(tmp == tmp1) {
                        st1.pop() ;
                    }   
                    else {
                        break ;
                    }
                }
            }
            index1++ ;   
        }       
        return st1.empty() ;
    }
};
int main()
{
    vector<int>ls1 ;
    vector<int>ls2 ;
    Solution ss ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) break ;
        ls1.push_back(a) ;
    }
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) break ;
        ls2.push_back(a) ;
    }
    cout << ss.IsPopOrder(ls1, ls2) << endl ;
    return 0;
}

