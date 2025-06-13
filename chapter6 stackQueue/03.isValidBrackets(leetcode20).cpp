#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution
{
public:
    //法一
    bool isValid(string s)
    {
        unordered_map<char, char> BracketMap = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}};
        stack<char> bracketStack;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
            {
                bracketStack.push(s[i]);
            }
            else
            {
                if (bracketStack.empty())
                    return false; // If stack is empty, it means unbalanced parentheses
                char topval = bracketStack.top();
                if (BracketMap[topval] != s[i])
                    return false;
                else
                {
                    bracketStack.pop();
                }
            }
        }
        if (!bracketStack.empty())
            return false;
        return true;
    }
    //法二
    bool isValid(string s)
    {
        stack<char> bracketStack;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='(') bracketStack.push(')');
            else if(s[i]=='[') bracketStack.push(']');
            else if(s[i]== '{') bracketStack.push('}');
            else if(bracketStack.empty()|| s[i]!=bracketStack.top()) return false;
            else bracketStack.pop();
        }
        return bracketStack.empty();
    }
};