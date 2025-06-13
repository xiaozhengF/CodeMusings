#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> result_map;
        int count = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                int sum = nums1[i] + nums2[j];
                result_map[sum]++;
            }
        }
        for (int k = 0; k < nums3.size(); k++)
        {
            for (int l = 0; l < nums4.size(); l++)
            {
                auto it = result_map.find(-(nums3[k] + nums4[l]));
                if (it != result_map.end())
                {
                    count += it->second;
                }
            }
        }
        return count;
    }
};