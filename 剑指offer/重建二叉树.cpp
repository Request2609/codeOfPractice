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
    //重建二叉树
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
        //根据先序遍历的第一个元素(树的根节点),找出中序遍历结果中根节点的下标
        for(int i=0; i<len; i++) {
            if(pre[0] == vin[i]) {
                index = i ;
                break ;
            }
        }
        //记录左子树的先序遍历结果和后序遍历结果
        //将左子树的先序遍历结果存在leftpre数组（左子树的先序遍历结果）
        //将中序遍历的左子树结果存在leftin数组（左子树的中序遍历结果）
        for(int i=0; i<index; i++) {
            leftpre.push_back(pre[i+1]) ;
            leftin.push_back(vin[i]) ;
        }
        //记录右子树的先序遍历结果和中序遍历结果
        for(int i=index+1; i<len; i++) {
            //将右子树的先序遍历结果存在rightpre（右子树的先序遍历结果集合）
            rightpre.push_back(pre[i]) ;
            //将左子树的线序遍历结果存在rightin集合
            rightin.push_back(vin[i]) ;
        }
        //继续递归，返回结果作为左子树
        head->left = reConstructBinaryTree(leftpre, leftin) ;
        //继续递归，返回结果作为右子树
        head->right = reConstructBinaryTree(rightpre, rightin) ;
        //返回根节点的值
        return head ;
    }
};

int main() {

    return 0;
}

