#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> path;
    void backTracking(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            results.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!path.empty() && find(path.begin(), path.end(), nums[i]) != path.end())
                continue;
            path.push_back(nums[i]);
            backTracking(nums);
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {

        backTracking(nums);
        return results;
    }
};
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
            used[i] = true;
            path.push_back(nums[i]);
            backTracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        results.clear();
        vector<bool> used(nums.size(), false);
        backTracking(nums, used);
        return results;
    }
};