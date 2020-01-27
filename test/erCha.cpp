#include <iostream>
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool hasPathSum(TreeNode* root, int sum) {
        if(sum == 0) {
            return 0 ;
        }
        int ret = getRes(root, sum) ;
        return ret ;
    }

    bool getRes(TreeNode* root, int sum) {
        int ret = 0 ;
        if(root != NULL) {
            sum-=root->val ;   
            if(sum == 0) {
                if(root->right==NULL&&root->left == NULL) {
                    return 1 ;
                }
                else {
                    return 0 ;
                }
            }
            ret = getRes(root->left, sum) ;
            if(ret == 1) {
                return 1;
            }
            ret = getRes(root->right, sum) ;
            if(ret == 1) {
                return 1;
            }
        } 
        return 0 ;
    }
};

class Solution1 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL && root->val == sum)
            return true;     // 是叶子结点且路径和满足
        if (hasPathSum(root->left, sum-root->val))
            return true;
        if (hasPathSum(root->right, sum-root->val))
            return true;
        return false;
    }
};
int main() {

    return 0;
}

