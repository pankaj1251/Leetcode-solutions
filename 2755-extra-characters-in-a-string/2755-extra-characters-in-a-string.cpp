class Solution {
public:
    int func(string &s, int idx, set<string>&st, vector<int>&dp)
    {
        if(idx==s.length())return 0;
        
        if(dp[idx] != -1)return dp[idx];

        int ans=1e9;
        for(int i=idx; i<s.size(); i++)
        {
            string temp = s.substr(idx, i-idx+1);
        
            if(st.find(temp) != st.end())
            {
                ans= min({ans, func(s, i+1, st, dp)});
            }
        }

        ans = min(ans, 1 + func(s, idx+1, st, dp));

        return dp[idx] = ans;
    }

    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        set<string>st;
        for(auto &it: dict)st.insert(it);
        vector<int>dp(n, -1);

        return func(s, 0, st, dp);
    }
};