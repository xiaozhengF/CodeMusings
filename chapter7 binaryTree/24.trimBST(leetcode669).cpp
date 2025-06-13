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
//递归法
        TreeNode* trimBST(TreeNode* root, int low, int high) {
            if(!root) return nullptr;
            if(root->val < low){
                return trimBST(root->right, low, high);
            }
            if(root->val > high){
                return trimBST(root->left, low, high);
            }
            root->left=trimBST(root->left, low, high);
            root->right=trimBST(root->right, low, high);
            return root;
        }
        //迭代法
        TreeNode* trimBST(TreeNode* root, int low, int high) {
            while(root && (root->val < low || root->val > high)){
                if(root->val < low ) root = root->right;
                else if(root->val > high) root = root->left;
            }
            if(!root) return nullptr;
            for(auto node=root;node->left;){
                if(node->left->val<low){
                    node->left=node->left->right;
                }else{
                    node=node->left;
                }
            }
            for(auto node=root;node->right;){
                if(node->right->val>high){
                    node->right=node->right->left;
                }else{
                    node=node->right;
                }
            }
            return root;
        }
};