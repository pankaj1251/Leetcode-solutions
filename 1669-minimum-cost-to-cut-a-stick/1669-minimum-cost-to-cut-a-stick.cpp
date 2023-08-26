class Solution {
public:
    int func(vector<int>&arr, int start, int end, int i, int j, vector<vector<int>> &dp){
        if(i>j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans=INT_MAX;
        for(int idx=i; idx<=j; idx++){
            ans = min(ans, (end-start) + func(arr, start, arr[idx], i, idx-1, dp) + func(arr, arr[idx], end, idx+1, j, dp));
        }

        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& arr) {
        int len = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>>dp(len, vector<int>(len, -1));
        return func(arr, 0, n, 0, len-1, dp);
    }
};