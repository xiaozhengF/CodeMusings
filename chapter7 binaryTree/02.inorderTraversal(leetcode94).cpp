
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        Traversal(root,result);
        return result;  
    }
    void Traversal(TreeNode* cur,vector<int> &vec){
        if(cur == NULL) return;
        Traversal(cur->left,vec);
        vec.push_back(cur->val);
        Traversal(cur->right,vec);
    }
    //迭代法
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        TreeNode *cur;
        cur = root;
        stack<TreeNode *> st;
        while(cur||!st.empty()){
            if(cur){
                st.push(cur);
                cur=cur->left;
            }else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        TreeNode *lastVisited = NULL;

        while (!stack.empty() || curr)
        {
            while (curr)
            {
                stack.push(curr);
                curr = curr->left;
            }

            TreeNode *peekNode = stack.top();
            stack.pop();
            result.push_back(peekNode->val);
            if(peekNode->right){
                curr = peekNode->right;
            }
        }

        return result;
    }
    //统一迭代法
    vector<int> inorderTraversal(TreeNode* root) {
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
                st.push(temp);
                st.push(nullptr);
                if(temp->left)st.push(temp->left);
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