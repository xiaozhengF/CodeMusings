#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int len = s.size();
        int i;
        for (i = 2 * k; i <= len; i += 2 * k)
        {
            swap(s, i - 2 * k, i - k);
        }
        i -= 2 * k;
        int leftlen = len - i;
        if (leftlen < k)
            swap(s, i, len);
        else if (leftlen < 2 * k)
            swap(s, i, i + k);
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
    string reverseStr2(string s, int k)
    {
        int len = s.size();
        for(int i = 0;i<len;i+=2*k){
            if(i+k<=len){
                reverse(s.begin()+i,s.begin()+i+k);
                continue;
            }
            reverse(s.begin()+i,s.end());
        }
        return s;
    }
};