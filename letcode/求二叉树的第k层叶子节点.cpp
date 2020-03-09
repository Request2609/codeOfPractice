#include <iostream>
#include "binarytree.h"

//求二叉树的第k层的叶子节点
int getKLevelLeafNumber(TreeNode*root, int k) {
    if(root==NULL||k<=0) {
        return 0 ;
    }
    if(root!=NULL&&k==1) {
        if(root->left==NULL&&root->right==NULL) {
            return 1 ;
        }
        return 0 ;
    }
    //左子树第k层叶子节点个数+右子树叶子节点个数
    return getKLevelLeafNumber(root->left, k-1)+getKLevelLeafNumber(root->right, k-1) ;
}


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

