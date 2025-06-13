
#include <vector>
#include <stack>
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
    // 递归法
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        Traversal(root, result);
        return result;
    }
    void Traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;
        Traversal(cur->left, vec);
        Traversal(cur->right, vec);
        vec.push_back(cur->val);
    }
    // 迭代法
    vector<int> postorderTraversal(TreeNode *root)
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

            // 如果有右子节点并且右子节点没有被访问过
            if (peekNode->right && lastVisited != peekNode->right)
            {
                curr = peekNode->right; // 还没处理右子树
            }
            else
            {
                result.push_back(peekNode->val);
                lastVisited = stack.top();
                stack.pop();
            }
        }

        return result;
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode* cur;

        while (!st.empty())
        {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        int len = result.size();
        for(int i = 0;i<len/2;i++){
            int temp = result[i];
            result[i] = result[len-i-1];
            result[len-i-1] = temp;
        }

        return result;
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode *> stack;
        TreeNode *curr = root,*peekNode;
        TreeNode *lastVisited = NULL;

        while (!stack.empty() || curr)
        {
            if (curr)
            {
                stack.push(curr);
                curr = curr->left;
            }else{
                peekNode = stack.top();
                // 如果有右子节点并且右子节点没有被访问过
                if (peekNode->right && lastVisited != peekNode->right)
                {
                    curr = peekNode->right; // 还没处理右子树
                }
                else
                {
                    result.push_back(peekNode->val);
                    lastVisited = stack.top();
                    stack.pop();
                }
            }
        }

        return result;
    }
    //统一迭代法
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        TreeNode *temp;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            temp = st.top();
            if(temp){
                st.pop();
                st.push(temp);
                st.push(nullptr);
                if(temp->right)st.push(temp->right);
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