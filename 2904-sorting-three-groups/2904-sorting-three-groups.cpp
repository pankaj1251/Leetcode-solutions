class Solution {
public:
    int minimumOperations(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n,1);
        int m=1;
        for(int i=1;i<n;i++)
        {
            for(int prev=0; prev<i; prev++)
            {
                if(v[i]>=v[prev])
                {
                    dp[i]=max(dp[i],1+dp[prev]);
                    m=max(m,dp[i]);
                }
            }
        }
        return n-m;
    }
};