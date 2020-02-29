#include <iostream>
#include <vector>
#include "binarytree.h"
using namespace std ;

class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
         vector<vector<int>>ls ;  
         vector<int>res ;
         getRes(root, ls, res, expectNumber) ;
         return ls ;
    }

    void getRes(TreeNode* root,  vector<vector<int>>&ls, vector<int>res, int expnum) {
        if(root) {
            int tmp = expnum-root->val  ;          
            if(tmp==0&&root->left&&root->right) {
                res.push_back(root->val) ;
                ls.push_back(res) ;
                return ;
            }
            if(tmp == 0) return ;
            if(tmp < 0) { 
                return ; 
            }
            res.push_back(root->val) ;
            getRes(root->left, ls, res, tmp) ;
            getRes(root->right, ls, res, tmp) ;
        }
    }
};

int main()
{
    binarytree bt ;
    bt.build() ;
    auto root = bt.getRoot() ;
    if(root == NULL) {
        cout << "Kongde " << endl ;
    }
    bt.print() ;
    Solution ss ;
    int num = 0 ;
    cin >> num ;
    auto ls = ss.FindPath(root, num) ;
    cout << ls.size() << endl ;
    bt.destroy() ;
    return 0;
}

