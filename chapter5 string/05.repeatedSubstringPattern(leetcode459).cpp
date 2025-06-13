#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    //解法一 移动匹配
    bool repeatedSubstringPattern(string s) {
        string ss = s+s;
        ss.erase(ss.begin());
        ss.erase(ss.end()-1);//掐头去尾
        if(ss.find(s)!=std::string::npos) return true;
        return false;

    }
    void getNext(int *next, const string &s){
        int j = 0;
        next[0] = 0;
        for(int i = 1;i<s.size();i++){
            while(j>0&&s[i]!=s[j]){
                j = next[j-1];
            }
            if(s[i]==s[j]){
                j++;
            }
            next[i] = j;
        }
    } 
    //解法2 KMP实现
    bool repeatedSubstringPattern(string s) {
        const int len = s.size(); 
        int next[len];
        getNext(next,s);
        if(next[len - 1] != 0&&len%(len-next[len-1])==0) return true;
        return false;
    }
};
int main(void){
    Solution a;
    string s = "abcabc";
    a.repeatedSubstringPattern(s);
    return 0;
}