#include "binarytree.h"

struct TreeNode* binarytree::getRoot() {
    return root ;
}

void binarytree::build() {
    if(root == NULL) {
        int a ;
        cin>> a ;
        root =(TreeNode*)malloc(sizeof(struct TreeNode)) ;
        root->val = a ;
        root->left = NULL ;
        root->right = NULL ;
        build(&(root->left)) ;
        build(&(root->right)) ;
    }
}
void binarytree::build(struct TreeNode** node) {
    int a ;
    cin >> a ;
    if(a != -1) {
        (*node) = (TreeNode*)malloc(sizeof(TreeNode));
        (*node)->val = a ;
        (*node)->left = NULL ;
        (*node)->right = NULL ;
        build(&((*node)->left)) ;
        build(&((*node)->right)) ;
    }
}

void binarytree::print() {
    print(root) ;
}

void binarytree::print(TreeNode* node) {
    if(node) {
        cout << node->val <<"  " ;
        print(node->left) ;
        print(node->right) ;
    }   
}

void binarytree::destroy() {
    destroy(root) ;
}

void binarytree::destroy(TreeNode* node) {
    if(node) {
        if(node->left == NULL&&node->right == NULL) {
            free(node) ;
            node = NULL ;
            return ;
        }
        destroy(node->left) ;
        destroy(node->right) ;
    }
}
