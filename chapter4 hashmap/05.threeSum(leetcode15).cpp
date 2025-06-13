#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
                    continue;
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end())
                {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);
                }
                else
                {
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
    // 双指针法
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] > 0)
                break;
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            int left = k + 1, right = nums.size() - 1;
            while (left < right)
            {
                if (nums[k] + nums[left] + nums[right] > 0)
                    right--;
                else if (nums[k] + nums[left] + nums[right] < 0)
                    left++;
                else
                {
                    result.push_back({nums[k], nums[left], nums[right]});
                    while ((left < right) && nums[left] == nums[left + 1])
                        left++;
                    while ((left < right) && nums[right] == nums[right - 1])
                        right--;
                    left += 1;
                    right -= 1;
                }
            }
        }
        return result;
    }

};
int main(void)
{
    Solution a;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = a.threeSum(nums);
    for (const auto &row : result)
    { // 遍历每一行
        for (int num : row)
        {                       // 遍历行中的每个元素
            cout << num << " "; // 打印元素
        }
        cout << endl; // 每打印完一行后换行
    }
}