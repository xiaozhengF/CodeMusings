#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        removeExtraSpaces(s);
        swap(s, 0, s.size());
        int i, j =0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                swap(s, j, i);
                j = i + 1;
            }
        }
        swap(s, j, i);
        return s;
    }
    void swap(string &s, int l, int r)
    {
        for (int i = 0; i < (r - l) / 2; i++)
        {
            s[l + i] ^= s[r - i - 1];
            s[r - i - 1] ^= s[l + i];
            s[l + i] ^= s[r - i - 1];
        }
    }
    void removeExtraSpaces(string &s)
    {
        int fastindex = 0, slowindex = 0;
        while (s.size() > 0 && fastindex < s.size() && s[fastindex] == ' ')
            fastindex++;
        for (; fastindex < s.size(); fastindex++)
        {
            if (fastindex - 1 > 0 && s[fastindex - 1] == s[fastindex] && s[fastindex] == ' ')
            {
                continue;
            }
            else
            {
                s[slowindex++] = s[fastindex];
            }
        }
        if (slowindex - 1 > 0 && s[slowindex - 1] == ' ')
        {
            s.resize(slowindex - 1);
        }
        else
        {
            s.resize(slowindex);
        }
    }
};
int main(void)
{
    Solution a;
    string s = "  the sky  is  blue    ";
    a.reverseWords(s);
    return 0;
}