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
    TreeNode* parent;
    //递归法 有返回值
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            if(!root) return new TreeNode(val);
            if(root->val>val)
                root->left=insertIntoBST(root->left,val);
            else if(root->val<val)
                root->right=insertIntoBST(root->right,val);
            return root;
        }
    //递归法 无返回值
    void Travel(TreeNode* cur, int val) {
        if(cur==NULL){
            TreeNode* node=new TreeNode(val);
            if(node->val>parent->val) parent->right=node;
            else if(node->val<parent->val) parent->left=node;
            return;
        }
        parent=cur;
        if(val>cur->val) Travel(cur->right, val);
        if(val<cur->val) Travel(cur->left, val);
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        parent=new TreeNode(0);
        if(!root) return new TreeNode(val);
        Travel(root, val);
        return root; 
    } 
    //迭代法
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* pre=nullptr,*cur;
        cur=root;
        while(cur){
            pre=cur;
            if(cur->val>val) {
                cur=cur->left;
            }else cur=cur->right;
        }
        TreeNode* node=new TreeNode(val);
        if(node->val>pre->val) pre->right=node;
        else pre->left=node;
        return root;
    }   
};