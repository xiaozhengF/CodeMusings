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
//递归一
    void Traversal(TreeNode *root, vector<int> &paths, vector<string> &result)
    {
        paths.push_back(root->val);
        if (!root->left && !root->right)
        {
            string path;
            for (int i = 0; i < paths.size() - 1; i++)
            {
                path += to_string(paths[i]);
                path += "->";
            }
            path += to_string(paths[paths.size() - 1]);
            result.push_back(path);
        }
        if (root->left)
        {
            Traversal(root->left, paths, result);
            paths.pop_back();
        }
        if (root->right)
        {
            Traversal(root->right, paths, result);
            paths.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        vector<int> paths;
        if (!root)
            return result;
        Traversal(root, paths, result);
        return result;
    }
//递归二
    void Traversal(TreeNode *root, string path, vector<string> &result)
    {
        path+=to_string(root->val);
        if (!root->left && !root->right)
        {
            result.push_back(path);
        }
        if (root->left)
        {
            Traversal(root->left, path+"->", result);
        }
        if (root->right)
        {
            Traversal(root->right, path+"->", result);
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        string path;
        if (!root)
            return result;
        Traversal(root, path, result);
        return result;
    }
//迭代三 求二叉树的所有路径
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        if (!root)
            return result;
        stack<pair<TreeNode*,string>> st;
        st.push({root,""});
        while(!st.empty()) {
            auto [node,path] = st.top();
            st.pop();
            if(path.empty()){
                path+=to_string(node->val);
            }else{
                path+="->"+to_string(node->val);
            }
            if(!node->left&&!node->right) {
                result.push_back(path);
            }
            if(node->right){
                st.push({node->right,path});
            }
            if(node->left){
                st.push({node->left,path});
            }
        }
        return result;
    }
};