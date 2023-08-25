class Solution {
public:
    bool func(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp){
        if(i==s1.length() and j==s2.length() and k==s3.length())return true;

        if(dp[i][j] != -1)return dp[i][j];
        
        bool b1=false, b2=false;
        if(i != s1.length()) {
            if(s1[i]==s3[k])
                b1=func(s1, s2, s3, i+1, j, k+1, dp);
        }
        
        if(j != s2.length()){
            if(s2[j]==s3[k])
                b2=func(s1, s2, s3, i, j+1, k+1, dp);
        } 

        return dp[i][j] = b1||b2;
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        int n1=s1.length(), n2 = s2.length(), n3=s3.length();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        return func(s1, s2, s3, 0, 0, 0, dp); 
    }
};