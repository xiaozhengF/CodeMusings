#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<string>> results;
    vector<string> path;
    bool ishuiwen(const string &s, int lIndex, int RIndex)
    {
        while (lIndex < RIndex)
        {
            if (s[lIndex] == s[RIndex])
            {
                lIndex++;
                RIndex--;
            }
            else
                return false;
        }
        return true;
    }
    void backTracking(const string &s, int startIndex)
    {
        if (startIndex == s.size())
        {
            results.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (ishuiwen(s, startIndex, i))
            {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
                backTracking(s, i + 1);
                path.pop_back();
            }
            else
                continue;
        }
    }
    vector<vector<string>> partition(string s)
    {
        backTracking(s, 0);
        return results;
    }
};