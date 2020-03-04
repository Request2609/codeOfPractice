#include <iostream>
#include <stack>
using namespace std ;
//用两个栈来实现一个队列，
//完成队列的Push和Pop操作。
//队列中的元素为int类型。
class Solution {
public:
    void push(int node) {
        cout << node << endl ;
        stack1.push(node) ;
    }

    int pop() {
        if(!stack2.empty()) {
            int num = stack2.top() ;
            stack2.pop() ;
            return num ;
        }
        while(!stack1.empty()) {
            int num = stack1.top() ;
            stack2.push(num) ;
            stack1.pop() ;
        }
        int res = stack2.top() ;
        stack2.pop() ;
        return res ;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    Solution ss ;
    cout << "插入"<< endl ;
    ss.push(1) ;
    ss.push(2) ;
    ss.push(3) ;
    ss.push(4) ;
    ss.push(5) ;
    ss.push(6) ;
    ss.push(7) ;
    cout << "---------------" << endl ;
    cout << ss.pop() << endl ;
    cout << ss.pop() << endl ;
    cout << ss.pop() << endl ;
    cout << ss.pop() << endl ;
    cout << ss.pop() << endl ;
    cout << ss.pop() << endl ;
    cout << ss.pop() << endl ;
    return 0;
}

