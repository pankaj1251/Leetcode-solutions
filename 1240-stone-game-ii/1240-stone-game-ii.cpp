class Solution {
public:
    int func(vector<int>& arr, int i, int n, int M, int turn, vector<vector<vector<int>>> &dp)
    {
        if(i>=n)return 0;
        if(dp[i][M][turn] != -1)return dp[i][M][turn];
        int ans = turn==1?0:INT_MAX;
        
        if(turn){
            int score=0;
            for(int j=0; j<2*M; j++){
                if(i+j>=n)break;
                score += arr[i+j];
                ans = max(ans, score + func(arr, i+j+1, n, max(M,j+1), !turn, dp)); //here we are taking i+j+1, dry run you'll understand 
            }
        }
        else{
            for(int j=0; j<2*M; j++){
                if(i+j>=n)break;
                ans = min(ans, func(arr, i+j+1, n, max(M,j+1), !turn, dp));
            }
        }

        return dp[i][M][turn] = ans;
    }

    int stoneGameII(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        return func(arr, 0, n, 1, 1, dp);
    }
};