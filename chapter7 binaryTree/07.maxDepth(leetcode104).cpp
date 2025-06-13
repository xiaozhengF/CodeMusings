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
    int result = 0;
    // 递归法
    int maxDepth(TreeNode *root)
    {
        return getHeight(root);
    }
    int getHeight(TreeNode *node)
    {
        if (!node)
            return 0;
        int lh = getHeight(node->left);
        int rh = getHeight(node->right);
        return max(lh, rh) + 1;
    }
    // 后序遍历迭代法
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> que;
        TreeNode *temp;
        que.push(root);
        int depth = 0;
        while (!que.empty())
        {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++)
            {
                temp = que.front();
                que.pop();
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
            }
        }
        return depth;
    }
    // 前序遍历迭代法
    int maxDepth(TreeNode *node)
    {
        result = 0;
        if (!node)
            return result;
        getDepth(node, 1);
        return result;
    }
    void getDepth(TreeNode *node, int Depth)
    {
        result = Depth > result ? Depth : result;
        if (!node->left && !node->right)
            return;
        if (node->left)
        {
            getDepth(node->left, Depth + 1);
        }
        if (node->right)
        {
            getDepth(node->right, Depth + 1);
        }
        return;
    }
};