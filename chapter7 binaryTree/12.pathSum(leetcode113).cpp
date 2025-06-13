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
//迭代法
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (!root)
            return res;
        stack<pair<TreeNode*, vector<int>>> st;
        vector<int> path;
        st.push({root, path});
        while (!st.empty()) {
            auto [node, path] = st.top();
            st.pop();
            path.push_back(node->val);
            if (!node->left && !node->right) {
                int val = 0;
                for (int i = 0; i < path.size(); i++)
                    val += path[i];
                if (val == targetSum)
                    res.push_back(path);
            }
            if (node->right) {
                st.push({node->right, path});
            }
            if (node->left) {
                st.push({node->left, path});
            }
        }
        return res;
    }
//递归法
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<int> path;
        Traversal(root,targetSum,res,path);
        return res;
    }
    void Traversal(TreeNode* Node,int targetSum,vector<vector<int>>&res,vector<int>&path) {
        path.push_back(Node->val);
        if(!Node->left&&!Node->right&&targetSum==Node->val){
            res.push_back(path);
            return;
        }
        targetSum-=Node->val;
        if(Node->left){
            Traversal(Node->left,targetSum,res,path);
            path.pop_back();
        }
        if(Node->right){
            Traversal(Node->right,targetSum,res,path);
            path.pop_back();
        }
    }
};