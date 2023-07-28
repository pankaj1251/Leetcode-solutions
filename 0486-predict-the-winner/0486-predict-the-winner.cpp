class Solution {
public:

    int func(vector<int>& arr, bool flag, int i, int j, vector<vector<vector<int>>> &dp)
    {
        if(i>=arr.size() || j<0 || i>j)return 0;

        if(dp[flag][i][j] != -1)return dp[flag][i][j];
        
        if(flag) return dp[flag][i][j] = max(arr[i] + func(arr, !flag, i+1, j, dp), arr[j] + func(arr, !flag, i, j-1, dp));
        
        else return dp[flag][i][j] = min(-arr[i] + func(arr, !flag, i+1, j, dp), -arr[j] + func(arr, !flag, i, j-1, dp));
    }
    bool PredictTheWinner(vector<int>& arr) {

        int n = arr.size();
        vector<vector<vector<int>>>dp(2, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = func(arr, true, 0, n-1, dp);
        
        return ans>=0;
    }
};