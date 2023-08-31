class Solution {
public:
    int func(vector<int>&arr, int idx, int k, vector<int> &dp){
        if(idx>=arr.size())return 0;
        if(dp[idx] != -1)return dp[idx];

        int ans=INT_MIN, maxm=arr[idx];
        for(int i=idx; i<k+idx and i<arr.size();i++)
        {
            maxm=max(maxm, arr[i]);
            
            int temp = (i-idx+1)*maxm;
            ans = max(ans, temp + func(arr, i+1, k, dp));
        }

        return dp[idx] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(), -1);
        return func(arr, 0, k, dp);
    }
};