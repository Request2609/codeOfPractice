#include <iostream>
#include <vector>
#include <stack>
using namespace std; 
int largestRectangleArea(vector<int>& heights) {
     heights.push_back(0);
     stack<int> stk;
     int maxArea = 0;
     for(int i = 0;i<(int)heights.size();i++)
     {
         while(!stk.empty() && heights[i]<heights[stk.top()])
         {
             int top= stk.top();
             stk.pop();
             maxArea = max(maxArea,heights[top]*(stk.empty()? i:(i - stk.top() -1)));
         }
         cout << maxArea << endl ;
         stk.push(i);
     }
     return maxArea;
}


int main() {
    vector<int>height ;
    while(1) {
        int a ;
        cin >> a ;
        if (a == -1) break ;
        height.push_back(a) ;
    }
    largestRectangleArea(height) ;
    //cout << largestRectangleArea(height) << endl ;
    return 0;
}

