#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
//n个整数的无序数组，找到每个元素后面比它大的第一个数，要求时间复杂度为O(N)
vector<int> find(vector<int> &num)
{
    int len = num.size();
    //空数组，返回空
    if(len == 0)
        return {};
    stack<int> notFind;//栈：num中还未找到符合条件的元素索引
    vector<int> res(len, -1);//返回结果：初始化-1，表示未找到
    int i = 0;
    while(i < len)//遍历数组
    {
        //如果栈空或者当前num元素不大于栈顶，将当前元素压栈，索引后移
        if(notFind.empty() || num[notFind.top()] >= num[i])
            notFind.push(i++);
        else//有待处理元素，且num当前元素大于栈顶索引元素，符合条件，更新结果数组中该索引的值，栈顶出栈。
        {
            res[notFind.top()] = num[i];
            notFind.pop();
        }
    }
    return res;
}
 
int main()
{
    vector<int> num = {1, 3, 2, 4, 99, 101, 5, 8};
    // vector<int> num = {1, 1, 1, 1, 1, 1, 1};
    // vector<int> num = {};
    vector<int> res = find(num);
    for(auto i : res)
        cout << i << "  ";
 
    return 0;
}
