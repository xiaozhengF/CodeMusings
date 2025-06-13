#include <string>
using namespace std;
class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
                j = next[j - 1];
            if (s[i] == s[j])
                j++;
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle)
    {
        const int len = needle.size();
        int next[len];
        getNext(next, needle);
        int i, j;
        for (i = 0, j = 0; i < haystack.size() && j < needle.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
                j++;
        }
        if (j < needle.size())
            return -1;
        return i - j + 1;
    }
};