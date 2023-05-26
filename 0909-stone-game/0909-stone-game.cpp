class Solution {
public:
    int func(vector<int>& piles, int i, int j, bool turn, vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(turn){
            int t1 = func(piles, i+1, j, false, dp) + piles[i];
            int t2 = func(piles, i, j-1, false, dp) + piles[j];

            return dp[i][j] = max(t1, t2);
        }

        else{
            int t1 = func(piles, i+1, j, true, dp) - piles[i];
            int t2 = func(piles, i, j-1, true, dp) - piles[j];

            return dp[i][j] = min(t1, t2);
        }
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return func(piles, 0, n-1, true, dp);
    }
};