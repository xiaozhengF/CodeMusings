#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((j > i + 1) && (nums[j] == nums[j - 1]))
                    continue;
                int l, r;
                l = j + 1;
                r = nums.size() - 1;
                while (l < r)
                {
                    long long subvalue = target - (nums[l] + nums[r]);
                    if (nums[i] + nums[j] > subvalue)
                    {
                        r--;
                    }
                    else if (nums[i] + nums[j] < subvalue)
                    {
                        l++;
                    }
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l = l + 1;
                        r = r - 1;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    }
                }
            }
        }
        return result;
    }
};