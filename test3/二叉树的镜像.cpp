#include <iostream>
#include "binarytree.h"

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot) {
            if(pRoot->right!=NULL&&pRoot->left!=NULL) {
                swap(&(pRoot->left), &(pRoot->right)) ;
            }
            else if(pRoot->right != NULL && pRoot->left == NULL) {
                pRoot->left = pRoot->right ;
                pRoot->right = NULL ;
            }
            else if(pRoot->left != NULL && pRoot->right == NULL) {
                pRoot->right = pRoot->left ;
                pRoot->left = NULL ;
            }
            Mirror(pRoot->left) ;
            Mirror(pRoot->right) ;
        }
    }
    void swap(TreeNode** left, TreeNode** right) {
        TreeNode* cur = *left ;
        *left = *right ;
        *right = cur ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

