/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
#include<stack>
using namespace std;
 struct TreeNode {
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        Traversal(root,result);
        return result;  
    }
    void Traversal(TreeNode* cur,vector<int> &vec){
        if(cur == NULL) return;
        vec.push_back(cur->val);
        Traversal(cur->left,vec);
        Traversal(cur->right,vec);
    }
    //迭代法
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        TreeNode *temp;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            temp = st.top();
            st.pop();
            result.push_back(temp->val);
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        return result;
    }
    //统一迭代法
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        TreeNode *temp;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            temp = st.top();
            if(temp){
                st.pop();
                if(temp->right)st.push(temp->right);
                if(temp->left)st.push(temp->left);
                st.push(temp);
                st.push(nullptr);
            }else{
                st.pop();
                temp = st.top();
                result.push_back(temp->val);
                st.pop();
            }
        }
        return result;
    }
};