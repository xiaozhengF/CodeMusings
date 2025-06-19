#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> subset;
    void backTracking(vector<int> &nums, int startIndex)
    {
        results.push_back(subset); // 收集子集，要放在终止添加的上面，否则会漏掉自己
        if (startIndex >= nums.size())
            return;
        for (int i = startIndex; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            backTracking(nums, i + 1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        results.clear();
        subset.clear();
        backTracking(nums, 0);
        return results;
    }
};