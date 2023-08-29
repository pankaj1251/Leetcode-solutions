class Solution {
public:
    int func(vector<int>&arr, int idx, int lane, vector<vector<int>> &dp){
        if(idx==arr.size()-1)return 0;
        
        if(dp[idx][lane] != -1)return dp[idx][lane];

        if(arr[idx+1] != lane) return dp[idx][lane] = func(arr, idx+1, lane, dp);

        int ans=INT_MAX;
        for(int k=1; k<=3; k++){
            if(lane == k || arr[idx] == k)continue;
            ans = min(ans, 1+func(arr, idx, k, dp));
        }

        dp[idx][lane] = ans;
        
        return ans;
    }
    int minSideJumps(vector<int>& arr) {
        int n = arr.size();   
        vector<vector<int>>dp(n, vector<int>(4, -1));
        return func(arr, 0, 2, dp);
    }
};