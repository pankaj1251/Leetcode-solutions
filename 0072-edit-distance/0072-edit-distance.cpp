class Solution {
public:
    int func(string str1, int n1, string str2, int n2,  vector<vector<int>> &dp){
        if(n1<=0)return n2;
        if(n2<=0)return n1;
        if(dp[n1][n2] != -1)return dp[n1][n2];

        if(str1[n1-1]==str2[n2-1]){
            return dp[n1][n2] = func(str1, n1-1, str2, n2-1, dp);
        }

        return dp[n1][n2] = 1 + min(func(str1, n1-1, str2, n2-1, dp), min(func(str1, n1-1, str2, n2, dp), func(str1, n1, str2, n2-1, dp)));
        
    }
    int minDistance(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        return func(str1, n1, str2, n2, dp);
    }
};