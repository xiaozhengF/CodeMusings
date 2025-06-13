
#include <vector>
#include <stack>
#include <queue>
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
    //递归解法
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        invert(root);
        return root;
    }
    void invert(TreeNode* root) {
        if(!root) return;
        invert(root->left);
        invert(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    //层次遍历迭代解法
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            TreeNode* left = temp->left;
            temp->left = temp->right;
            temp->right = left;
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
        }
        return root;
    }
};