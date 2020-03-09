#include <iostream>
#include "binarytree.h"
//判断二叉树是否为平衡二叉树
class Solution {
public :
    //要是二叉树为空，返回真
    //如果二叉树不为空，如果左子树和右子树高度差不大于1并且
    //左子树和右子树都是avl树返回真，否则返回假
    bool isBalance(TreeNode*root) {
        if(root == NULL) {
            return true ;
        }
        return abs(maxHigh(root->left)-maxHigh(root->right))<=1&&
            isBalance(root->right)&&isBalance(root->left) ;
    }
    //求深度
    int maxHigh(TreeNode* root) {
        if(root==NULL) {
            return 0 ;
        }
        return max(maxHigh(root->left), maxHigh(root->right))+1 ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

