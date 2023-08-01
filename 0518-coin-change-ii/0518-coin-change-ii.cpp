class Solution {
public:
    int func(vector<int> &arr, int k, int idx, vector<vector<int>> &dp){
        if(k==0)return 1;
        if(idx<0)return 0;
        if(dp[idx][k] != -1)return dp[idx][k];
        if(arr[idx]>k)return dp[idx][k] = func(arr, k, idx-1, dp);
        return dp[idx][k] = func(arr, k-arr[idx], idx, dp) + func(arr, k, idx-1, dp);
    }
    int change(int amount, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return func(arr, amount, n-1, dp);
    }
};