class Solution {
public:
    int func(vector<int>&arr, int idx, int fee, bool flag, vector<vector<int>>&dp){
        if(idx==arr.size())return 0;
        if(dp[idx][flag]!=-1)return dp[idx][flag];

        int ans=0;

        if(flag) {
            // ans = max(-arr[idx]+func(arr, idx+1, fee, false, dp), func(arr, idx+1, fee, true, dp));
            int buy = -arr[idx] + func(arr, idx+1, fee, false, dp);

            int no_buy = func(arr, idx+1, fee, true, dp);

            ans = max(buy, no_buy);
        }
        else{

            // ans = max(arr[idx]+func(arr, idx+1, fee, true, dp) - fee, func(arr, idx+1, fee, false, dp));

            int sell = arr[idx] - ans - fee + func(arr, idx+1, fee, true, dp);

            int no_sell = func(arr, idx+1, fee, false, dp);

            ans = max(sell, no_sell);
        }

        return dp[idx][flag] = ans;
    }

    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return func(arr, 0, fee, true, dp);
    }
};