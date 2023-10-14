class Solution {
public:
    int func(vector<int>&cost, vector<int>&time, int idx, int walls, vector<vector<int>>&dp){
        if(walls<=0)return 0;
        if(idx<0)return 1e9;

        if(dp[idx][walls] != -1)return dp[idx][walls];
        // when painter 1 will be busy we will change the number of wall remaining to : walls - time[i] - 1(-1 for current wall and time[i] are the walls painted by free painter or painter 2). 
        int take = cost[idx]+func(cost, time, idx-1, walls - time[idx] - 1, dp);
        int not_take = func(cost, time, idx-1, walls, dp);

        return dp[idx][walls] = min(take, not_take);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return func(cost, time, n-1, n, dp);
    }
};