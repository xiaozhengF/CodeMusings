#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // 解法：使用unordered_map来存储每一个元素及其下标
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> result_map;
        for (int i = 0; i < nums.size(); i++) {
            auto it = result_map.find(target - nums[i]);
            if (it == result_map.end()) {
                result_map.insert(pair<int,int>(nums[i],i));
            } else {
                return {it->second, i};
            }
        }
        return {};
    }
    // 暴力解法
    vector<int> twoSum2(vector<int>& nums, int target) {
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};