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
//迭代法
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode *cur=root;
        while(cur){
            if(cur->val>p->val&&cur->val>q->val) cur=cur->left;
            else if(cur->val<p->val&&cur->val<q->val) cur=cur->right;
            else return cur;
        }
        return nullptr;
    }
//递归法
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(!root) return nullptr;
        if(root->val>p->val&&root->val>q->val) return lowestCommonAncestor(root->left, p,q);
        if(root->val<p->val&&root->val<q->val) return lowestCommonAncestor(root->right, p,q);
        return root;
    }
};