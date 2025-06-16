#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> path;
    int sum = 0;
    void backTracking(int n, int k, int startIndex)
    {
        if (path.size() == k && sum == n)
        {
            results.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9; i++)
        {
            path.push_back(i);
            sum += i;
            backTracking(n, k, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
    // 剪枝操作
    void backTracking(int n, int k, int startIndex)
    {
        if (path.size() == k && sum == n)
        {
            results.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            sum += i;
            if (sum <= n)
                backTracking(n, k, i + 1); // 剪枝操作
            sum -= i;
            path.pop_back();
        }
    }

    void backTracking(int n, int k, int startIndex)
    {
        if (path.size() == k && n == 0)
        {
            results.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            n -= i;
            if (n >= 0)
                backTracking(n, k, i + 1); // 剪枝操作
            n += i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backTracking(n, k, 1);
        return results;
    }
};