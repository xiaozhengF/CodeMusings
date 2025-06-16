#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> path;
    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            results.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) 
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    // 剪枝操作
    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            results.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) // 这里有剪枝优化
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return results;
    }
};