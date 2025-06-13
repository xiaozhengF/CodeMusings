#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int applyOp(int a, int b, char op) {  
        switch (op) {  
            case '+': return a + b;  
            case '-': return a - b;  
            case '*': return a * b;  
            case '/': return a / b;  
        }  
        return 0;  
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> tokenStack;
        for (string token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int num2 = tokenStack.top();
                tokenStack.pop();
                int num1 = tokenStack.top();
                tokenStack.pop();
                tokenStack.push(applyOp(num1, num2, token[0]));
            }else{
                tokenStack.push(stoi(token));
            }
        }
        return tokenStack.top();
    }
};