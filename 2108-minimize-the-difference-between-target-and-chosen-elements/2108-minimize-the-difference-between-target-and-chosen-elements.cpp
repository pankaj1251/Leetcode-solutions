class Solution {
public:
    int n, m;
    int func(vector<vector<int>>&arr, int i, int k, int res, vector<vector<int>> &dp){
        if(i>=n)return abs(res-k);
        
        if(dp[i][res] != -1)return dp[i][res];

        int ans=INT_MAX;
        for(int j=0; j<m; j++){
            ans = min(ans, func(arr, i+1, k, res+arr[i][j], dp));

            if(ans==0)break;
        }
        return dp[i][res] = ans;
    }
    int minimizeTheDifference(vector<vector<int>>& arr, int target) {
        n = arr.size();
        m = arr[0].size();
        vector<vector<int>>dp(n+1, vector<int>(10000, -1));
        int res = func(arr, 0, target, 0, dp);

        return res;
    }
};