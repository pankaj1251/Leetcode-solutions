class Solution {
public:
    int func(vector<int>&arr, int idx, int sum1, int sum2, vector<vector<int>> &dp){
        if(idx==arr.size()){
            return abs(sum1-sum2);
        }

        if(dp[idx][sum1] != -1)return dp[idx][sum1];

        return dp[idx][sum1] = min(func(arr, idx+1, sum1 + arr[idx], sum2, dp), func(arr, idx+1, sum1 , sum2+ arr[idx], dp));
    }
    int lastStoneWeightII(vector<int>& arr) {
        int sum=0, n=arr.size();
        sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));

        int ans = func(arr, 0, 0, 0, dp);

        return ans;
    }
};