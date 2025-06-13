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
//递归法
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if(nums.size()==0) return nullptr;
        int left=0,right=nums.size();
        return Travel(nums,left,right);
    }
    TreeNode *Travel(vector<int> &nums,int left,int right){
        if(right<=left) return nullptr;
        int middle=left+(right-left)/2;
        TreeNode* Node = new TreeNode(nums[middle]);
        Node->left=Travel(nums,left,middle);
        Node->right=Travel(nums,middle+1,right);
        return Node;
    }
//迭代法
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if(nums.size()==0) return nullptr;
    queue<TreeNode *> nodeQue;
    queue<int> leftQue;
    queue<int> rightQue;
    TreeNode *root = new TreeNode(0),*cur;
    nodeQue.push(root);
    leftQue.push(0);
    rightQue.push(nums.size());
    while(!nodeQue.empty()){
        cur=nodeQue.front();
        nodeQue.pop();
        int left=leftQue.front();
        leftQue.pop();
        int right=rightQue.front();
        rightQue.pop();
        int middle=left+(right-left)/2;
        cur->val=nums[middle];
        if(left<middle){
            cur->left=new TreeNode(0);
            nodeQue.push(cur->left);
            leftQue.push(left);
            rightQue.push(middle);
        }
        if(right>middle+1){
            cur->right=new TreeNode(0);
            nodeQue.push(cur->right);
            leftQue.push(middle+1);
            rightQue.push(right);
        }
    }
    return root;
}
};