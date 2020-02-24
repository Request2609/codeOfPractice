#include <iostream>
#include "binarytree.h"

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL) return true ;
        int left = getRes(pRoot->left) ;
        int right = getRes(pRoot->right) ;
        if(abs(left-right) > 1) {
            return false ;
        }
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right) ;
    }

    bool getRes(TreeNode*pRoot) {
        if(pRoot == NULL) {
            return 0 ;
        }
        int left = getRes(pRoot->left) ;
        int right = getRes(pRoot->right) ;
        return left>right?(left+1):(right+1) ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

