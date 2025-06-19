#include <set>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> path;
    void backTracking(vector<int> &nums, int startIndex)
    {
        if (path.size() >= 2)
            results.push_back(path);
        if (startIndex >= nums.size())
            return;
        set<int> used;
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (!path.empty() && nums[i] < path.back() || used.count(nums[i]))
                continue;
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        results.clear();
        path.clear();
        backTracking(nums, 0);
        return results;
    }
};