#pragma once
#include <iostream>
using namespace std ;
struct TreeNode {
    int val ;
    struct TreeNode* left ;
    struct TreeNode* right ;
} ;

class binarytree {
public:
    binarytree() {
        root = NULL ;
    }
    ~binarytree() {}
    void build() ;    
    void build(struct TreeNode** node) ;
    struct TreeNode* getRoot() ;
    void destroy() ;
    void print() ;
    void print(TreeNode* node) ;
private:
    void destroy(TreeNode* node) ;
    struct TreeNode* root;
};

