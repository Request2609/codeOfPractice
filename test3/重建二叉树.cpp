#include <iostream>
#include <vector>
using namespace std ;
/*
输入某二叉树的前序遍历和中序遍历的结果，
请重建出该二叉树。假设输入的前序遍历和
中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}
和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。 
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len = vin.size() ;
        if(len < 0) {
            return NULL ;
        }
        vector<int>leftpre, rightpre ;
        vector<int>leftin, rightin ;
        //创建新节点
        TreeNode* head = new TreeNode(pre[0]) ;
        int index = 0 ;
        for(int i=0; i<len; i++) {
            if(pre[0] == vin[i]) {
                index = i ;
                break ;
            }
        }
        //记录左子树的先序遍历结果和后序遍历结果
        for(int i=0; i<index; i++) {
            leftpre.push_back(pre[i+1]) ;
            leftin.push_back(vin[i]) ;
        }
        //记录右子树的先序遍历结果和中序遍历结果
        for(int i=index+1; i<len; i++) {
            rightpre.push_back(pre[i]) ;
            rightin.push_back(vin[i]) ;
        }
        //继续递归
        head->left = reConstructBinaryTree(leftpre, leftin) ;
        head->right = reConstructBinaryTree(rightpre, rightin) ;
        return head ;
    }
    
    void getRes(TreeNode** root, int pindex, int mindex, vector<int>&pre, vector<int>&vin) {
        int lenp = pre.size() ;
        int lenv = vin.size() ;
        if(pindex >= lenp||mindex>lenv) {
            return ;
        }
        int tmp = pre[pindex] ;
        int mid = 0 ;
        for(int i=0; i<lenv; i++) {
            if(tmp == vin[i]) {
                mid = i ;
                break ;
            }   
        }
        *root = (TreeNode*)malloc(sizeof(TreeNode)) ;
        (*root)->val = tmp ;
    }
};

int main() {

    return 0;
}

