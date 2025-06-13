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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if(!root) return nullptr;
        if(root->val>key){
            root->left=deleteNode(root->left, key);
        }else if(root->val<key){
            root->right=deleteNode(root->right, key);
        }else{
            if(!root->left&&!root->right) return nullptr;
            else if(!root->left&&root->right) return root->right;
            else if(root->left&&!root->right) return root->left;
            else {
                TreeNode* temp=root->left;
                while(temp->right) temp=temp->right;
                root->val=temp->val;
                root->left=deleteNode(root->left, root->val);
                return root;
            }
        }
        return root;
    }
};