#include <iostream>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        if(n) return generate(1, n) ;
        else return std::vector<TreeNode*>{} ;
    }

    std::vector<TreeNode*>generate(int left, int right) {
        std::vector<TreeNode*>ans ;
        if(left > right) {
            ans.push_back(NULL) ;
            return ans ;
        }
        for(int i=0; i<=right; i++) {
            //向两边扩展
            //向做扩展，边界为left
            std::vector<TreeNode*>left_node = generate(left, i-1) ;
            //向右扩展，边界为right
            auto right_node = generate(i+1, right) ;
            for(auto l : left_node) {
                for(auto r:right_node) {
                    TreeNode* t = new TreeNode(i) ;
                    t->left = l ;
                    t->right = r ;
                    ans.push_back(t) ;
                }
            }
        }
        return ans;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

