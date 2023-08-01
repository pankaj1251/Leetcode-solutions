class Solution {
public:
    int func(vector<int> &arr, int k, int idx, vector<vector<int>> &dp){
        if(k==0)return 0; //if amount is zero, we need 0 coins.
        if(idx<0)return INT_MAX-1;

        if(dp[idx][k] != -1)return dp[idx][k];

        if(arr[idx]>k)return dp[idx][k] = func(arr, k, idx-1, dp);

        int take = func(arr, k-arr[idx], idx, dp);
        int not_take = func(arr, k, idx-1, dp);

        return dp[idx][k] = min(1+take, not_take);
    }
    int coinChange(vector<int>& arr, int amount) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans=func(arr, amount, n-1, dp);
        return ans==INT_MAX-1?-1:ans;
    }
};