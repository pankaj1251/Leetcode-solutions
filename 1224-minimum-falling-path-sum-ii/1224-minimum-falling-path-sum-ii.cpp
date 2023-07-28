class Solution {
public:
    // int func(vector<vector<int>>& arr, int i, int j, vector<vector<int>> &dp){
    //     if(i>=arr.size() || j<0 || j>=arr.size())return 0;
    //     if(i==arr.size()-1){
    //         return arr[i][j];
    //     }
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int ans=INT_MAX;
    //     for(int idx=0; idx<arr.size(); idx++){
    //         if(idx==j)continue;
    //         ans = min(ans, arr[i][j] + func(arr, i+1, idx, dp));
    //     }

    //     return dp[i][j] = ans;
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
                int minm = INT_MAX;
                for(int k=0; k<n; k++){
                    if(j==k)continue;
                    minm = min(minm, arr[i][j] + dp[i-1][k]);
                }
                dp[i][j] = minm;
            }
        }

        for(int i=0; i<n; i++){
            // ans = min(ans, func(arr, 0, i, dp));
            ans = min(ans, dp[arr.size()-1][i]);
        }
        return ans;
    }
};