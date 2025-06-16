#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
    void backTracking(int target, vector<int> &candidates, int startIndex)
    {
        // 这里要判断是否大于target，大于则直接返回
        if (sum > target)
            return;
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(target, candidates, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backTracking(target, candidates, 0);
        return result;
    }
};
// 排序做剪枝优化
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(int target, vector<int> &candidates, int startIndex)
    {
        if (0 == target)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && (target - candidates[i] >= 0); i++)
        {
            path.push_back(candidates[i]);
            backTracking(target - candidates[i], candidates, i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        backTracking(target, candidates, 0);
        return result;
    }
};