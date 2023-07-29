class Solution {
public:
    bool func(vector<int>& arr, int i, int sum, vector<vector<int>> &dp){
        if(i>=arr.size() or sum<0)return false;
        if(sum==0)return true;

        if(dp[i][sum] != -1)return dp[i][sum];

        if(arr[i] > sum)return dp[i][sum] = func(arr, i+1, sum, dp);

        return dp[i][sum] = func(arr, i+1, sum, dp) || func(arr, i+1, sum-arr[i], dp);
    }
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int n = arr.size();
        for(auto it: arr)sum += it;
        if(sum%2 != 0)return false;
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        
        return func(arr, 0, sum/2, dp);
    }
};