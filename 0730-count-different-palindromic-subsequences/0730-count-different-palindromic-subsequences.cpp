class Solution {
public:
    int func(string &s, int start, int end, vector<vector<int>>&dp){
        if(start>end)return 0;

        if(start==end)return 1;

        if(dp[start][end] != -1)return dp[start][end];

        int ans=0;

        if(s[start]==s[end])
        {
            int left=start+1, right=end-1;

            while(left<=right and s[start] != s[left]){
                left++;
            }
            while(left<=right and s[end] != s[right]){
                right--;
            }

            if(left<right){
                ans += 2*func(s, start+1, end-1, dp)-func(s, left+1, right-1, dp);
            }
            else if(left==right){
                ans += 2*func(s, start+1, end-1, dp)+1;
            }
            else{
                ans += 2*func(s, start+1, end-1, dp)+2;
            }
        }
        else{
            ans += func(s, start+1, end, dp) + func(s, start, end-1, dp) - func(s, start+1, end-1, dp);
        }


        return dp[start][end] = ans<0 ? ans+1000000007 : ans%1000000007;
    }

    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return func(s, 0, n-1, dp);
    }
};