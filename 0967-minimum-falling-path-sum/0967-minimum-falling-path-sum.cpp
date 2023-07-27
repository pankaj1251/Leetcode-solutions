class Solution {
public:
    //Memoization (TLE)
    
    // int func(vector<vector<int>>& arr, int i, int j, vector<vector<int>> &dp){
    //     if(i==0 and j>=0 and j<arr.size())return arr[i][j];
    //     if(j<0 || j>= arr.size())return INT_MAX-10;
    //     if(dp[i][j] != -1)return dp[i][j];
    //     return dp[i][j] = arr[i][j] + min(func(arr, i-1, j, dp), min(func(arr, i-1, j-1, dp), func(arr, i-1, j+1, dp)));
    // }

    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int ans = INT_MAX;

        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++){
            dp[0][i] = arr[0][i];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = arr[i][j] + dp[i-1][j];

                int leftUp = arr[i][j];
                if(j>0)leftUp += dp[i-1][j-1];
                else leftUp += 1e8;
                
                int rightUp = arr[i][j];
                if(j+1<n)rightUp += dp[i-1][j+1];
                else rightUp += 1e8;
                
                dp[i][j] = min(up, min(leftUp, rightUp));
            }
        }

        for(int i=0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }

        return ans;
    }
};