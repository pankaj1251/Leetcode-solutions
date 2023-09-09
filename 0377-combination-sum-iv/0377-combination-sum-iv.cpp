class Solution {
public:
    int func(vector<int>&arr, int idx, int k, vector<vector<int>> &dp)
    {
        if(k<0 || idx==arr.size())return 0;
        if(k==0)return 1;
        if(dp[idx][k] != -1)return dp[idx][k];

        int ans=0;
        for(int i=0; i<arr.size(); i++){
            int temp =  k-arr[i];
            ans += func(arr, i,temp, dp);
        }

        return dp[idx][k] = ans;
    }
    int combinationSum4(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return func(arr, 0, target, dp);
    }
};