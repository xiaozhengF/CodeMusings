#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i = 0;i<len/2;i++){
            char temp;
            temp = s[i];
            s[i] = s[len-i-1];
            s[len-i-1] = temp;
        }
    }
    void reverseString2(vector<char>& s) {
        int j = s.size()-1,i = 0;
        while (i<j)
        {
            s[i]^=s[j];
            s[j]^=s[i];
            s[i]^=s[j];
            i++;
            j--;
        }
    }
};