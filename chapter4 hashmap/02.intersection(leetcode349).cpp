#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        for(int i = 0;i<nums1.size();i++) {
            for(int j = 0;j<nums2.size();j++) {
                    if(nums1[i] == nums2[j]){
                        result.insert(nums1[i]);
                        break;
                    }
            }
        }
        return vector<int>(result.begin(),result.end());
    }
    // 解法2
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> nums(nums1.begin(),nums1.end());
        for(int num : nums2) {
            if(nums.find(num) != nums.end()){
                result.insert(num);
            }
        }
        return vector<int>(result.begin(),result.end());
    }
};