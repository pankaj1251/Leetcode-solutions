class Solution {
public:
    int func(vector<int> &arr, int sum, int i, int k, vector<vector<int>> &dp){
        if(i>arr.size())return 0;
        if(i==arr.size()){if(sum==k)return 1; else return 0;}
        if(dp[i][sum+1000] != -1)return dp[i][sum+1000];

        int add = func(arr, sum + arr[i], i+1, k, dp);
        int subtract = func(arr, sum - arr[i], i+1, k, dp);
        
        return dp[i][sum+1000] = add + subtract;
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(2001, -1));
        return func(arr, 0, 0, target, dp);
    }
};