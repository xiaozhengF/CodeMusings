#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
//递归法
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val==val) return root;
        if(val>root->val) return searchBST(root->right,val);
        if(val<root->val) return searchBST(root->left,val);
        return root;
    }
//迭代法
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        while(root){
            if(val==root->val) return root;
            else if(val > root->val) root = root->right;
            else root = root->left;
        }
        return nullptr;
    }
};