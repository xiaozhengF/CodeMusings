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
    TreeNode* preNode;
//迭代法
    bool isValidBST(TreeNode* root) {
        vector<int> travelOrder;
        stack<TreeNode*>st;
        TreeNode* cur = root;
        while(!st.empty()|| cur){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                travelOrder.push_back(cur->val);
                cur = cur->right;
            }
        }
        for(int i = 1;i<travelOrder.size();i++){
            if(travelOrder[i]<=travelOrder[i-1]) return false;
        }
        return true;
    }
//迭代法2
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* cur = root,*preNode=nullptr;
        while(!st.empty()|| cur){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                if(preNode&&preNode->val>=cur->val) return false;
                preNode = cur;
                cur = cur->right;
            }
        }
        return true;
    }
//递归法
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool lb = isValidBST(root->left);
        if(preNode&&preNode->val>=root->val) return false;
        preNode = root;
        bool rb = isValidBST(root->right);
        return lb&&rb;
    }
};