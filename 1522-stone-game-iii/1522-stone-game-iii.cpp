class Solution {
public:
    int func(vector<int>& arr, int i, bool flag, vector<vector<int>>&dp)
    {
        if(i>=arr.size())return 0;
        if(dp[i][flag] != -1)return dp[i][flag];
        
        int score=0;
        int ans = flag==1 ? INT_MIN : INT_MAX; //in case of alice we need to find max ans , so we set ans to INT_MIN.
        int n = arr.size();
        
        for(int j=i; j < min(i+3, n); j++){ //we are starting from i here.

            if(flag){
                score += arr[j];
                ans = max(ans, score + func(arr, j+1, !flag, dp));
            }
            else{
                score -= arr[j];
                ans = min(ans, score + func(arr, j+1, !flag, dp));
            }
        }

        return dp[i][flag] = ans;
    }
    string stoneGameIII(vector<int>& arr) 
    {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        int ans = func(arr, 0, true, dp);
        
        if(ans<0) return "Bob";
        if(ans>0) return "Alice";
        return "Tie";
    }
};