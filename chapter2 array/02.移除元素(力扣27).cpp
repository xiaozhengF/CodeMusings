#include<iostream>
#include<cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    // 双指针法
    int removeElement(vector<int>& nums, int val) {
        int current = 0;
        for(int i = 0;i< nums.size();i++){
            if(nums[i] != val){
                nums[current++] = nums[i];
            }
        }
        return current;
    }
    // 暴力解法
    int removeElement2(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0;i<size;i++){
            if(nums[i] == val){
                for(int j = i+1;j<size;j++){
                    nums[j-1] = nums[j];
                }
                i--;
                size--;
            }
        }
        return size;
    }    
};