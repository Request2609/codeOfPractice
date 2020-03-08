#include <iostream>
#include <vector>
#include <stack>
#include "binarytree.h" 
class Solution {
public :
    //先序非递归遍历二叉树
    void travelFirst(TreeNode*root) {
        std::stack<TreeNode*>st ; 
        auto res = root ;
        while(res||!st.empty()) {
            if(res != NULL) {
                std::cout << res->val << " " ;
                st.push(res) ;
                res = res->left ;
            }
            else {
                res = st.top() ;
                res = res->right ;
                st.pop() ;
            }
        }
    }
    //中序遍历非递归实现
    void travelMid(TreeNode* root) {
        stack<TreeNode*>st ;
        auto res = root ;
        while(res||!st.empty()) {
            if(res!=NULL) {
                st.push(res) ;
                res = res->left ;
            }
            else {
                res = st.top() ;
                std::cout << res->val << std::endl ;
                res = res->right ;
                st.pop() ;
            }       
        }
    }   
    //后续遍历非递归
    void lastTravel(TreeNode* root) {
        std::stack<TreeNode*>st ;
        auto res = root ;
        while(res||st.empty()) {
            if(res) {
                st.push(res) ;
                res = res->left ;
            }
            if(!st.empty()){
                res = st.top() ;
                //要是第一次遍历的
                //各节点设置标志，已经走过了
                if(res->val == 0) {
                    res->val = 1 ;
                    res = res->right ;
                }
                //已经是第二次到达这个节点了，打
                //印出当前节点的值，并弹出当前节点
                 else {
                    std::cout << res->val << std::endl ;
                    st.pop() ;
                    res = NULL ;
                }
            }
        }
    }
};

int main()
{
    return 0;
}

