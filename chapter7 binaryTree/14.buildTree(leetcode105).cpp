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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0) return nullptr;
        return build(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
    TreeNode* build(vector<int>& preorder,int preorderbegin,int preorderend, vector<int>& inorder,int inorderbegin,int inorderend){
        if(preorderbegin==preorderend)return nullptr;
        TreeNode* root = new TreeNode(preorder[preorderbegin]);
        if(preorderend-preorderbegin==1) return root;
        int rootIndex;
        for(rootIndex=inorderbegin;rootIndex<inorderend;rootIndex++){
            if(inorder[rootIndex]==root->val) break;
        }
        int llinOrderIndex = inorderbegin;
        int lrinOrderIndex = rootIndex;
        int rlinOrderIndex = rootIndex+1;
        int rrinOrderIndex = inorderend;
        int llpreOrderIndex = preorderbegin+1;
        int lrpreOrderIndex = llpreOrderIndex+lrinOrderIndex-llinOrderIndex;
        int rlpreOrderIndex = lrpreOrderIndex;
        int rrpreOrderIndex = preorderend;
        root->left = build(preorder,llpreOrderIndex,lrpreOrderIndex,inorder,llinOrderIndex,lrinOrderIndex);
        root->right = build(preorder,rlpreOrderIndex,rrpreOrderIndex,inorder,rlinOrderIndex,rrinOrderIndex);
        return root;
    }
};