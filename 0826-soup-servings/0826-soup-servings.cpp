class Solution {
public:
    vector<vector<int>>dir = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};

    double dfs(int A, int B, vector<vector<double>> &dp){
        if(A<=0 and B<=0)return 0.5;
        if(A<=0 and B>0)return 1.0;
        if(B<=0 and A>0)return 0.0;
        if(dp[A][B] != -1)return dp[A][B];

        double total=0.0;
        for(int i=0; i<4; i++){
            int x = A - dir[i][0];
            int y = B - dir[i][1];
            total += dfs(x, y, dp);
        }

        return dp[A][B] = total*0.25;
    }
    double soupServings(int n) {
        if(n>4800)return 1.0;
        vector<vector<double>>dp(n+1, vector<double>(n+1, -1.0));
        return dfs(n, n, dp);
    }
};