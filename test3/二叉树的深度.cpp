#include <iostream>
#include "binarytree.h"

class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL) return 0 ;
        int deep = 1 ;
        int curMax = INT32_MIN ;
        getRes(curMax, deep, pRoot) ;   
        return curMax ;
    }
    void getRes(int &curMax, int deep, TreeNode* pRoot) {
        if(pRoot) {
            getRes(curMax, deep+1, pRoot->left) ;
            if(curMax < deep) {
                curMax = deep ;
            }
            getRes(curMax, deep+1, pRoot->right) ;
            if(curMax < deep) {
                curMax = deep ;
            }
        }
    }
};
int main()
{
    binarytree bt ;
    bt.build() ;
    TreeNode* root =bt.getRoot() ;
    Solution ss ;
    std::cout << ss.TreeDepth(root) << std::endl;
    bt.destroy() ;
    return 0;
}

