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
class Solution
{
public:
    TreeNode *preNode = nullptr;
    // 迭代法
    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
            return 0;
        TreeNode *cur = root, *preNode = nullptr;
        int result = INT32_MAX;
        stack<TreeNode *> st;
        while (!st.empty() || cur)
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                if (preNode)
                {
                    if (cur->val - preNode->val < result)
                        result = cur->val - preNode->val;
                }
                preNode = cur;
                cur = cur->right;
            }
        }
        return result;
    }
    // 递归法
    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
            return 0;
        int result = INT32_MAX;
        Travel(root, result);
        return result;
    }
    void Travel(TreeNode *root, int &result)
    {
        if (!root)
            return;
        Travel(root->left, result);
        if (preNode)
        {
            if (root->val - preNode->val < result)
                result = root->val - preNode->val;
        }
        preNode = root;
        Travel(root->right, result);
        return;
    }
};