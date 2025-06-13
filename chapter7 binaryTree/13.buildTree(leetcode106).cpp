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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0||postorder.size()==0) return nullptr;
        return Traversal(inorder,0,inorder.size(),postorder,0,postorder.size());
    }

    TreeNode* Traversal(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size()==0)return nullptr;
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        if(postorder.size()==1)return root;
        int rootIndex;
        for(rootIndex = 0;rootIndex<inorder.size();rootIndex++){
            if(inorder[rootIndex]==root->val) break;
        }
        vector<int>leftinOrder(inorder.begin(),inorder.begin()+rootIndex);
        vector<int>rightinOrder(inorder.begin()+rootIndex+1,inorder.end());
        vector<int>leftpostOrder(postorder.begin(),postorder.begin()+leftinOrder.size());
        vector<int>rightpostOrder(postorder.begin()+leftinOrder.size(),postorder.end()-1);  
        root->left = Traversal(leftinOrder,leftpostOrder);
        root->right = Traversal(rightinOrder,rightpostOrder);
        return root;
    }
    //使用下标
    TreeNode* Traversal(vector<int>& inorder, int leftinorderIndex,int rightinorderIndex,vector<int>& postorder,int leftpostorderIndex,int rightpostorderIndex){
        if(leftpostorderIndex==rightpostorderIndex)return nullptr;
        TreeNode* root = new TreeNode(postorder[rightpostorderIndex-1]);
        if(rightpostorderIndex-leftpostorderIndex==1)return root;
        int rootIndex;
        for(rootIndex = leftinorderIndex;rootIndex<rightinorderIndex;rootIndex++){
            if(inorder[rootIndex]==root->val) break;
        }
        int llinIndex = leftinorderIndex;
        int lrinIndex = rootIndex;
        int rlinIndex = rootIndex+1;
        int rrinIndex = rightinorderIndex;
        int llpostIndex = leftpostorderIndex;
        int lrpostIndex = leftpostorderIndex+lrinIndex-llinIndex;
        int rlpostIndex = lrpostIndex;
        int rrpostIndex = rightpostorderIndex-1;
        root->left = Traversal(inorder,llinIndex,lrinIndex,postorder,llpostIndex,lrpostIndex);
        root->right = Traversal(inorder,rlinIndex,rrinIndex,postorder,rlpostIndex,rrpostIndex);
        return root;
    }
};