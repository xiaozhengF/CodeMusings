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
    // 递归法
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return root1;
        if (root1 && !root2)
            return root1;
        if (!root1 && root2)
            return root2;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
    // 迭代法
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if(!root1) return root2;
        if(!root2) return root1;
        stack<pair<TreeNode *, TreeNode *>> st;
        st.push({root1, root2});
        while (!st.empty())
        {
            auto [node1, node2] = st.top();
            st.pop();
            node1->val += node2->val;

            if(node1->right&&node2->right){
                st.push({node1->right,node2->right});
            }else if(!node1->right){
                node1->right = node2->right;
            }

            if(node1->left&&node2->left){
                st.push({node1->left,node2->left});
            }else if(!node1->left){
                node1->left = node2->left;
            }
        }
        return root1;
    }
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2){
        if(!root1) return root2;
        if(!root2) return root1;
        queue<pair<TreeNode*,TreeNode*>> que;
        que.push({root1, root2});
        while(!que.empty()){
            auto [node1,node2] = que.front();
            que.pop();
            node1->val+=node2->val;
            if(node1->left&&node2->left){
                que.push({node1->left,node2->left});
            }
            if(node1->right&&node2->right){
                que.push({node1->right,node2->right});
            }
            if(!node1->left&&node2->left){
                node1->left = node2->left;
            }
            if(!node1->right&&node2->right){
                node1->right = node2->right;
            }
        }
        return root1;
    }
};