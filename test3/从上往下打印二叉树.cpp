#include <iostream>
#include <vector>
#include <queue>
#include "binarytree.h"

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int>ls ;
        if(root == NULL) { return ls; }
        queue<TreeNode*>que ;
        que.push(root) ;
        while(!que.empty()) {
            auto tmp = que.front() ;
            que.pop() ;
            if(tmp->left) {
                que.push(tmp->left) ;
            }
            if(tmp->right){
                que.push(tmp->right) ;
            }
            ls.push_back(tmp->val) ;
        }
        return ls ;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

