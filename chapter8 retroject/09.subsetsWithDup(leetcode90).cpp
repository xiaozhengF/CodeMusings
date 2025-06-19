#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> path;
    void backTracking(vector<int> &nums, int startIndex)
    {
        results.push_back(path);
        if (startIndex >= nums.size())
            return;
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > startIndex && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        results.clear();
        path.clear();
        sort(nums.begin(),nums.end());
        backTracking(nums, 0);
        return results;
    }
};