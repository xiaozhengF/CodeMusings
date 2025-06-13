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
    //递归法 1
    bool dfs(TreeNode *root,int targetSum){
        if(!root) return false;
        if(!root->left&&!root->right){
            return root->val == targetSum;
        }
        targetSum-=root->val;
        return dfs(root->left,targetSum)||dfs(root->right,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return dfs(root,targetSum);
    }
    //递归法2
    bool dfs(TreeNode* root, int targetSum) {
        if (!root->left && !root->right) {
            return targetSum == 0;
        }
        bool lb = false, rb = false;
        if (root->left) {
            lb = dfs(root->left, targetSum - root->left->val);
        }
        if (root->right) {
            rb = dfs(root->right, targetSum - root->right->val);
        }
        return lb || rb;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        return dfs(root, targetSum - root->val);
    }
    //迭代法
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        stack<pair<TreeNode*,int>> st;
        st.push({root,root->val});
        while(!st.empty()){
            auto [node,sum]  = st.top();
            st.pop();
            if(!node->left&&!node->right){
                if(sum == targetSum) return true;
            } 
            if(node->right){
                st.push({node->right,sum+node->right->val});
            }
            if(node->left){
                st.push({node->left,sum+node->left->val});
            }
        }
        return false;
    }
};