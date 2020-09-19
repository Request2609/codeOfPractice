#include <iostream>
#include <stack>
#include "binarytree.h"

using namespace std ;
class Tree {
public :
    //先序遍历非递归实现
    void travelFirst(TreeNode* root) {
        stack<TreeNode*>st ;
        auto res = root ;
        while(res||!st.empty()) {
            if(res!=NULL) {
                cout << res->val << endl ;
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

    //中序非递归遍历二叉树
    void midTravel(TreeNode* root) {
        stack<TreeNode*> st ;
        auto res = root ;
        while(res ||!st.size()) {
            if(res!=NULL) {
                st.push(res) ;
                res = res->left ;
            }
            else {
                res = st.top() ;
                cout << res->val << endl ;
                res = res->right ;
                st.pop() ;
            }
        }
    }
    //后序非递归遍历
    void lastTravel(TreeNode* root) {
        stack<TreeNode*>st ;   
        auto res = root ;
        while(res || !st.empty()) {
            if(res != NULL) {
                st.push(res) ;
                res = res->left ;
            }
            if(!st.empty()) {
                res = st.top() ;
                //判断标记
                if(res->val == 0) {
                    res->val = 1 ;
                    res = res->right ;
                }
                else {
                    cout << res->val << endl ;
                    st.pop() ;
                    res = NULL ;
                }
            }
        }
    } 
    //线索化二叉
} ;
int main()
{
    return 0;
}

