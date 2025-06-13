#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
//双指针解法
    int trap(vector<int>& height) {
        int sum  = 0;
        for(int i = 0;i<height.size();i++) {
            if(i==0||i==height.size()-1) continue;
            int lheight  = height[i];
            int rheight = height[i];
            for(int r = i+1;r<height.size();r++){
                if(height[r]>rheight) rheight = height[r];
            }
            for(int l = i-1;l>=0;l--){
                if(height[l]>lheight) lheight = height[l];
            }
            int h = min(lheight,rheight)-height[i];
            if(h>0) sum+=h;
        }
        return sum;
    }
//动态规划
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size(),0);
        vector<int> maxRight(height.size(),0);
        maxLeft[0] = height[0];
        maxRight[height.size()-1] = height[height.size()-1];
        for(int i = 1;i<height.size();i++){
            maxLeft[i] = max(height[i],maxLeft[i-1]);
        }
        for(int  i = height.size()-2;i>=0;i--){
            maxRight[i] = max(height[i],maxRight[i+1]);
        }
        int sum  = 0;
        for(int i = 0;i<height.size();i++) {
            if(i==0||i==height.size()-1) continue;
            int h = min(maxLeft[i],maxRight[i])-height[i];
            if(h>0) sum+=h;
        }
        return sum;
    }
//单调栈
    int trap(vector<int>& height) {
        stack<int> st;
        st.push(0);
        int sum;
        for(int i = 1;i<height.size();i++) {
            if(height[i]<height[st.top()]){
                st.push(i);
            }
            if(height[i]==height[st.top()]){
                st.pop();
                st.push(i);
            }else{
                while(!st.empty()&&height[i]>height[st.top()]){
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()){
                        int h = min(height[i],height[st.top()])-height[mid];
                        int w = i -st.top()-1;
                        sum+=h*w;
                    }
                    st.push(i);
                }
            }
        }
        return sum;
        }
};