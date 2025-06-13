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
class Solution
{
public:
    // 递归法
    int minDepth(TreeNode *root)
    {
        return getHeight(root);
    }
    int getHeight(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (leftHeight == 0)
            return rightHeight + 1;
        if (rightHeight == 0)
            return leftHeight + 1;
        return min(leftHeight, rightHeight) + 1;
    }
    //迭代法
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> que;
        TreeNode* temp;
        que.push(root);
        int depth = 0;
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i = 0;i<size;i++){
                temp = que.front();
                que.pop();
                if(!temp->left&&!temp->right)return depth;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
        }
        return depth;
    }
};