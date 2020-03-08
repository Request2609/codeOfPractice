#include <iostream>
#include <stack>
#include "binarytree.h"

class Solution {
public :
    TreeNode*Convert(TreeNode* pRootOfTree) {
        std::stack<TreeNode*>st ;      
        if(pRootOfTree == NULL) return pRootOfTree ;
        TreeNode* pre = pRootOfTree ;
        TreeNode* cur = pRootOfTree ;
        st.push(cur) ;
        int flag = 0 ;
        TreeNode* pRoot;
        while(!st.empty()) {
            while(cur&&cur->left) {
                cur=cur->left ;
                st.push(cur) ;
            }
            //判断要是最左边第一个节点
            if(flag == 0) {
                pRoot = pre ;
                pre = cur ;
                cur = cur->right ;
                flag = 1 ;
            }
            else {
                st.pop() ;
                auto s = st.top() ;
                pre->right = s ;
                s->left = pre ;
                pre = s ;
                cur = pre->right ;
            }
        }
        return pRoot ;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

