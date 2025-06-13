#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int temp[26] = {0};
        for(int i = 0;i<s.size();i++){
            temp[s[i]-'a']++;            
        }
        for(int i = 0;i<t.size();i++){
            temp[t[i]-'a']--; 
        }
        for(int j = 0;j<26;j++){
            if(temp[j]) return false;
        }
        return true;
    }
};