class Solution {
public:
    const int mod = 1e9+7;
    int func(int steps, int idx, int n, vector<vector<int>>&dp){
        if(steps==0 and idx==0)return 1;
        if(idx<0 ||  idx>=n || steps==0 || idx>steps)return 0;
        if(dp[steps][idx] != -1)return dp[steps][idx];
        return dp[steps][idx] = ((func(steps-1, idx+1, n, dp)%mod + func(steps-1, idx-1, n, dp))%mod + func(steps-1, idx, n, dp))%mod;
    }
    int numWays(int steps, int n) {
        vector<vector<int>>dp(steps+1, vector<int>(steps/2+1, -1)); //steps/2+1 bcz if idx reaches steps/2+1 it cannot reach back to '0'.
        return func(steps, 0, n, dp);
    }
};