class Solution {
public:
    int func(vector<int>arr, int start, int end,  vector<int>&dp){
        if(start >= end)return 0;
        if(dp[start] != -1)return dp[start];
        return dp[start] = max(func(arr, start+1, end, dp), arr[start]+func(arr, start+2, end, dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp1(nums.size(), -1);
        vector<int>dp2(nums.size(), -1);
        if(nums.size()==1)return nums[0];
        return max(func(nums, 0, nums.size()-1, dp1), func(nums, 1, nums.size(), dp2));
    }
};