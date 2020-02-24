#include <iostream>
#include "binarytree.h"
//输入两棵二叉树A，B，
//判断B是不是A的子结构。
//（ps：我们约定空树不是任意一个树的子结构）

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        bool res = false ;
        if(pRoot1&&pRoot2) {
            if(pRoot1->val == pRoot2->val)
                res = travel(pRoot1, pRoot2) ;
            if(!res) {
                res = HasSubtree(pRoot1->left, pRoot2) ;
            }
            if(!res) {
                res = HasSubtree(pRoot1->right, pRoot2) ;
            }
        }
            return res ;
    }

    bool travel(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot2&&pRoot1 == NULL) {
            return false ;
        }
        if(pRoot2 == NULL) {
            return true ;
        }
        if(pRoot1->val != pRoot2->val) {
            return false ;
        }
        return travel(pRoot1->left, pRoot2->left)&&travel(pRoot1->right, pRoot2->right) ;
    }
};
int main()
{   
    binarytree bt ;
    return 0;
}

