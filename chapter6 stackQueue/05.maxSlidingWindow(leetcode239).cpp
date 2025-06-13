#include<vector>
#include<deque>
using namespace std;
class MyQueue{
    public:
        deque<int>que;
    void push(int val){
        while(!que.empty()&&val>que.back()){
            que.pop_back();
        }
        que.push_back(val);
    }
    void pop(int val){
        if(!que.empty()&&val==que.front()){
            que.pop_front();
        }
    }
    int front(){
        return que.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue q;
        vector<int> ans;
        int i;
        for(i = 0;i<k;i++){
            q.push(nums[i]);
        }
        ans.push_back(q.front());
        while(i<nums.size()){
            q.pop(nums[i-k]);
            q.push(nums[i]);
            ans.push_back(q.front());
            i++;
        }
        return ans;
    }
};