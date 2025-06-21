#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<string>> results;
    vector<string> dashboard;
    bool isValid(int row, int col, int n)
    {
        int i, j;
        // 沿着垂直方向,剪枝
        for (i = 0; i < row; i++)
        {
            if (dashboard[i][col] == 'Q')
                return false;
        }
        // 沿着左上
        for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (dashboard[i][j] == 'Q')
                return false;
        }
        // 沿着右上
        for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (dashboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void backTracking(int n, int row)
    {
        if (n == row)
        {
            results.push_back(dashboard);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, n))
            {
                dashboard[row][col] = 'Q';
                backTracking(n, row + 1);
                dashboard[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        results.clear();
        dashboard.clear();
        dashboard = vector<string>(n, string(n, '.'));
        backTracking(n, 0);
        return results;
    }
};