#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string letterMap[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    // string path;
    void backTracking(string &digits, int index, string path)
    {
        if (index == digits.size())
        {
            result.push_back(path);
            return;
        }
        int digit = digits[index] - '0'; // 字符转为数字，不能使用int(digits[index]) 这样返回的是字符的ASCII值
        for (char ch : letterMap[digit])
        {
            // path.push_back(ch);
            // backTracking(digits, index + 1);
            // path.pop_back();
            backTracking(digits, index + 1, path + ch); // 隐藏回溯
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return result;
        backTracking(digits, 0, "");
        return result;
    }
};