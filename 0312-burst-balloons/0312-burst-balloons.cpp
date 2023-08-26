class Solution {
public:
    int func(vector<int>&arr, int i, int j, vector<vector<int>>&dp){
        if(i>j)return 0;

        if(i==j){
            int temp = arr[i];
            if(i-1>=0) 
                temp *= arr[i-1];
            if(j+1<arr.size()) 
                temp *= arr[j+1];
            return temp;
        }

        if(dp[i][j] != -1)return dp[i][j];

        int ans=0;

        for(int k=i; k<=j; k++)
        {
            int temp = arr[k];
            if(i-1>=0) 
                temp *= arr[i-1];
            if(j+1<arr.size()) 
                temp *= arr[j+1];

            temp += func(arr, i, k-1, dp) + func(arr, k+1, j, dp);

            ans = max(ans, temp);
        }

        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return func(arr, 0, n-1, dp);
    }
};