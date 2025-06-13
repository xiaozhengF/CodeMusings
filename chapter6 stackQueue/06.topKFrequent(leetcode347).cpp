#include<vector>
#include<queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    class  MyComparison{
        public:
            bool operator() (const pair<int,int>& lhs,const pair<int,int>& rhs){
                return lhs.second > rhs.second;
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i = 0;i<nums.size();i++){
            map[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,MyComparison> priQue;
        for(unordered_map<int,int>::iterator it = map.begin();it!=map.end();it++){
            priQue.push(*it);
            if(priQue.size()>k){
                priQue.pop();
            }
        }
        vector<int> result(k);
        for(int i = k-1;i>=0;i--){
            result[i] = priQue.top().first;
            priQue.pop();
        }
        return result;
    }
};