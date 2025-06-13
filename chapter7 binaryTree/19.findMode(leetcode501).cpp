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
        vector<int> findMode(TreeNode* root) {
            vector<int> res;
            if (!root) return res;
            
            TreeNode* cur = root;
            TreeNode* preNode = nullptr;
            int times = 0;
            int maxCount = 0;
            stack<TreeNode*> st;
            
            while (!st.empty() || cur) {
                if (cur) {
                    st.push(cur);
                    cur = cur->left;
                } else {
                    cur = st.top();
                    st.pop();
                    
                    // 处理当前节点
                    if (preNode && preNode->val == cur->val) {
                        times++;
                    } else {
                        if (preNode) {
                            // 处理前一个节点的出现次数
                            if (times > maxCount) {
                                maxCount = times;
                                res.clear();
                                res.push_back(preNode->val);
                            } else if (times == maxCount) {
                                res.push_back(preNode->val);
                            }
                        }
                        // 重置当前节点出现次数为1
                        times = 1;
                    }
                    preNode = cur;
                    cur = cur->right;
                }
            }
            
            // 处理最后一个节点
            if (preNode) {
                if (times > maxCount) {
                    maxCount = times;
                    res.clear();
                    res.push_back(preNode->val);
                } else if (times == maxCount) {
                    res.push_back(preNode->val);
                }
            }
            
            return res;
        }
    };