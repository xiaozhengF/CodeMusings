#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> path;
    void backTracking(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            results.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;
            // 这里used[i - 1]为true也是阔以，即树枝去重，对于排列问题，树层上去重和树枝上去重，都是可以的，但是树层上去重效率更高！
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1]==false) // 树层去重
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backTracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        results.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backTracking(nums, used);
        return results;
    }
};