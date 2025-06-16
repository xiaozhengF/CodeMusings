#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> path;
    void backTracking(int target, vector<int> &candidates, vector<bool> &used, int startIndex)
    {
        if (0 == target)
        {
            results.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && (target - candidates[i] >= 0); i++) // 剪枝优化
        {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) // 树层去重
                continue;
            path.push_back(candidates[i]);
            used[i] = true;
            backTracking(target - candidates[i], candidates, used, i + 1); // target - candidates[i] 隐藏回溯
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); // 先排序
        vector<bool> used(candidates.size(), false);
        backTracking(target, candidates, used, 0);
        return results;
    }
};
// 不用used数组去重
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> path;
    void backTracking(int target, vector<int> &candidates, int startIndex)
    {
        if (0 == target)
        {
            results.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && (target - candidates[i] >= 0); i++) // 剪枝优化
        {
            if (i > startIndex && candidates[i] == candidates[i - 1]) // 树层去重
                continue;
            path.push_back(candidates[i]);
            backTracking(target - candidates[i], candidates, i + 1); // target - candidates[i] 隐藏回溯
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); // 先排序
        backTracking(target, candidates, 0);
        return results;
    }
};