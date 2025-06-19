#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> results;
    vector<string> path;
    bool validIpadd(const string &s)
    {
        if (s.empty() || s.size() > 3)
            return false;
        if (s[0] == '0' && s.size() > 1)
            return false;
        int ip = stoi(s);
        return ip >= 0 && ip <= 255;
    }
    void backTracking(const string &s, int startIndex)
    {
        if (path.size() > 4)
            return;
        if (path.size() == 4 && startIndex == s.size())
        {
            string ipAdd = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
            results.push_back(ipAdd);
            return;
        }
        for (int i = startIndex; i < s.size() && i - startIndex < 3; i++)
        {
            string validadd = s.substr(startIndex, i - startIndex + 1);
            if (validIpadd(validadd))
            {
                path.push_back(validadd);
                backTracking(s, i + 1);
                path.pop_back();
            }
            else
                break;
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        results.clear();
        path.clear();
        backTracking(s, 0);
        return results;
    }
};

class Solution2
{
public:
    vector<string> results;
    bool validIpadd(const string &s)
    {
        if (s.empty() || s.size() > 3)
            return false;
        if (s[0] == '0' && s.size() > 1)
            return false;
        int ip = stoi(s);
        return ip >= 0 && ip <= 255;
    }
    void backTracking(string &s, int startIndex, int pointNum)
    {
        if (pointNum == 3)
        {
            string lastAdd = s.substr(startIndex, s.size() - startIndex);
            if (validIpadd(lastAdd))
            {
                results.push_back(s);
                return;
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            string validadd = s.substr(startIndex, i - startIndex + 1);
            if (validIpadd(validadd))
            {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backTracking(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            }
            else
                break;
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        results.clear();
        if (s.size() < 4 && s.size() > 12)
            return results;
        backTracking(s, 0, 0);
        return results;
    }
};