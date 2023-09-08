class Solution {
public:
    int func(int idx, int num, string &str, vector<vector<int>> &dp)
    {
        if(idx==str.size()){
            if(num%25==0)return 0;
            else return 1e9;
        }

        if(dp[idx][num] != -1)return dp[idx][num];

        int not_take = 1 + func(idx+1, num, str, dp);

        int digit = str[idx]-'0';
        int take = func(idx+1, (digit+num*10)%25, str, dp);

        return dp[idx][num] = min(take, not_take);
    }
    int minimumOperations(string str) {
        int n = str.size();
        vector<vector<int>>dp(n+1,vector<int>(25, -1));

        return func(0, 0, str, dp);
    }
};