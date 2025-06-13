#include <vector>
#include <stack>
#include <queue>
#include <math.h>
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
    // 递归法
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        if(lh==-1 || rh==-1) return false;
        return abs(lh-rh)<=1;
    }
    int getHeight(TreeNode *node)
    {
        if (!node)
            return 0;
        int lh = getHeight(node->left);
        int rh = getHeight(node->right);
        if(lh==-1||rh==-1)return -1;
        if(abs(lh-rh)>1) return -1;
        return max(lh, rh) + 1;
    }
    //迭代法
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> st;
        TreeNode*curr=root;
        TreeNode* lastVisited = nullptr;
        while(!st.empty()||curr){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            if(curr->right&&lastVisited != curr->right){
                curr = curr->right;
            }else{
                st.pop();
                int lh = getHeight(curr->left);
                int rh = getHeight(curr->right);
                if(abs(lh-rh)>1) return false;
                curr->val = max(lh,rh)+1;
                lastVisited = curr;
                curr = nullptr;
            }
        }
        return true;
    }
    int getHeight(TreeNode *node){
        return node ? node->val : 0;
    }
};