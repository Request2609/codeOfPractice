#include <iostream>
#include <stack>
using namespace std ;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) {
            return pRootOfTree ;
        }
        if(!pRootOfTree->left&&!pRootOfTree->right) {
            return pRootOfTree ;
        }
        //将左子树的构造成双链表
        TreeNode* left =Convert(pRootOfTree->left) ;
        TreeNode* p =left ;
        while(p&&p->right) {
            p = p->right ; ///p为左子树的右节点
        }
        if(left != NULL) {
            p->right = pRootOfTree ;  
            pRootOfTree->left = p ;
        }
        TreeNode* right = Convert(pRootOfTree->right) ;
        if(right) {
            right->left = pRootOfTree ;
            pRootOfTree->right = right ;
        }
        return left!=NULL?left:pRootOfTree ;
    }
    //非递归实现
    TreeNode* Convert1(TreeNode* root) {
        if(root == NULL) return NULL ;    
        stack<TreeNode*>st ;
        TreeNode* p = root ;
        TreeNode* rootList = NULL ;
        TreeNode* pre = NULL ;
        bool  isFirst = 1;
        while(p||!st.empty()) {
            while(p) {
                st.push(p) ;
                p = p->left ;
            }
            p = st.top() ;
            st.pop() ;
            if(isFirst) {
                isFirst =0 ;
                rootList = p ;
                pre = rootList ;
            }
            else {
                pre->right = p ;
                p->left = pre ;
                pre = p ;
            }
            p = p->right ;
        }
        return rootList ;
    }
    void getRes(TreeNode*cur, TreeNode* pre) {
        if(cur) {
            getRes(cur->left, cur) ;
            cur->right = pre ;
            cur = pre->right ;
            getRes(cur, pre) ;
            cur->left = pre ;
        }
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

