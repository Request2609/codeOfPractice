#include <iostream>
#include "binarytree.h"

class Solution {
public :
    void Mirror(TreeNode* pRoot) {
        if(pRoot) {
            if(pRoot->right!=NULL&&pRoot->left!=NULL) {
                swap(*(pRoot->left), (*pRoot->right)) ;       
                Mirror(pRoot->left) ;
                Mirror(pRoot->right) ;
            }
            if(pRoot->right==NULL&&pRoot->left!=NULL) {
                pRoot->right = pRoot->left ;
                pRoot->left = NULL ;
            }
            if(pRoot->right!=NULL&&pRoot->left==NULL) {
                pRoot->left = pRoot->right ;
                pRoot->right = NULL ;
            }
            Mirror(pRoot->left) ;
            Mirror(pRoot->right) ;
        }
    }    

    void swap(TreeNode& node1, TreeNode& node2) {
        auto no = std::move(node1) ;
        node1 = std::move(node2) ;
        node2 = std::move(no) ;
    }

};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

