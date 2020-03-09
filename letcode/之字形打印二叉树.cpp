#include <iostream>
#include <vector>
#include <stack>
#include "binarytree.h"

//基本思想:设置两个栈，s1存放偶数层，遍历s2节点的同事按照左子树，
//右子树的顺序加入s1，遍历s1的同时，按照右子树、左子树顺序加到s2
//二叉树的之字形打印
class Solution {
public :    
    std::vector<std::vector<int>>print(TreeNode*root) {
        std::vector<std::vector<int>>ls ;
        std::stack<TreeNode*>s1 ;
        std::stack<TreeNode*>s2 ;
        int flag = 1 ;
        if(root==NULL) {
            return ls ;
        }
        std::vector<int>tmp ;
        s2.push(root);
        while(!s1.empty()||!s2.empty()) {
            if(flag%2) {
                while(!s2.empty()) {
                    TreeNode* node = s2.top() ;
                    s2.pop() ;
                    tmp.push_back(node->val) ;
                    if(node->left) {
                        s1.push(node->left) ;
                    }
                    if(node->right) {
                        s1.push(node->right) ;
                    }
                }
            }
            if(flag%2==0) {
                while(!s1.empty()) {
                    TreeNode* cur = s1.top() ;
                    s1.pop() ;
                    tmp.push_back(cur->val) ;
                    if(cur->right != NULL) {
                        s2.push(cur->right) ;
                    }
                    if(cur->left) {
                        s2.push(cur->left) ;
                    }
                }
            }
            ls.push_back(tmp) ;
            flag ++ ;
        }
        return ls ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

