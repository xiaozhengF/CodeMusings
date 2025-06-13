#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution
{
public:
    // 暴力解法 超时
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int minlen = INT_MAX;
        int sum = 0;
        int sublen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum >= target)
                {
                    sublen = j - i + 1;
                    break;
                }
            }
            if (sublen < minlen)
                minlen = sublen;
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
    // 滑动窗口
    int minSubArrayLen2(int target, vector<int> &nums)
    {
        int minlen = INT32_MAX;
        int sum = 0;
        int sublen = 0;
        int i = 0;
        for(int j = 0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                sublen = j-i+1;
                if(sublen<minlen) minlen = sublen;
                sum-=nums[i++];
            }
        } 
        return minlen == INT32_MAX ? 0 : minlen;  
    }
};