#include <iostream>
#include <vector>
#include <queue>
#include "binarytree.h"

class Solution {
public :
    //层次遍历二叉树
    std::vector<int>PrintFromTopToButtom(TreeNode* root) {
        std::vector<int>ls ;
        if(root == NULL) return ls ;
        std::queue<TreeNode*>que ;
        if(!root) {
            return ls ;
        }
        que.push(root) ;
        while(!que.empty()) {
            auto tmp = que.front() ;
            ls.push_back(tmp->val) ;
            if(tmp->left) {
                que.push(tmp->left) ;
            }    
            if(tmp->right) {
                que.push(tmp->right) ;
            }
            que.pop() ;
        }
        return ls ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

