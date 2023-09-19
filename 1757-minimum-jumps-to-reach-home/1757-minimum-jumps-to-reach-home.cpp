class Solution {
public:
    int dfs(int idx, int a, int b, int x, unordered_set<int>&st, int flag, vector<vector<int>> &dp){
        if(idx==x)return 0;
        if(idx<0 || idx>6001 || st.find(idx) != st.end())return 1e9;
        if(dp[idx][flag] != -1)return dp[idx][flag];
        
        dp[idx][flag] = 1 + dfs(idx+a, a, b, x, st, 0, dp);
        
        if(flag==0) dp[idx][flag] = min(dp[idx][flag], 1 + dfs(idx-b, a, b, x, st, 1, dp));

        return dp[idx][flag];
    }
    int minimumJumps(vector<int>& arr, int a, int b, int x) {
        unordered_set<int>st(arr.begin(), arr.end());
        vector<vector<int>>dp(7001, vector<int>(2, -1));
        int ans = dfs(0, a, b, x, st, 0, dp);
        if(ans>=1e7)return -1;
        return ans;
    }
};