#include <iostream>
#include <vector>
#include "binarytree.h"

class Solution {
public:
    std::vector<std::vector<int>>findPath(TreeNode* root, int exp) {
        std::vector<std::vector<int>> ls ;
        std::vector<int>res ;
        getRes(root, ls, res, exp) ;
        return ls ;
    }
    void getRes(TreeNode*root, std::vector<std::vector<int>>&ls, 
                std::vector<int>res, int exp) {
        if(exp<=0&&root==NULL) {
            if(exp == 0) {
                ls.push_back(res) ;
            }
            return ;
        }
        if(root&&exp-root->val>=0) {
            res.push_back(root->val) ;
            getRes(root->left, ls, res, exp-root->val) ;
            getRes(root->right, ls, res, exp-root->val) ;
        }
    }
    void getRes1(TreeNode*root, std::vector<std::vector<int>>&ls, 
                std::vector<int>res, int exp) {
        if(root) {
            int tmp = exp-root->val ;
            if(tmp==0&&root->left&&root->right) {
                res.push_back(root->val) ;
                ls.push_back(res) ;
                return ;
            }
            if(tmp<0) return  ;
            res.push_back(root->val) ;
            getRes(root->left, ls, res, tmp) ;
            getRes(root->right, ls, res, tmp) ;
        }
    }
} ;

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

