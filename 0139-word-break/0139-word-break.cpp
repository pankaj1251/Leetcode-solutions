class Solution {
public:
    bool func(string &s, int idx, set<string>&st, vector<int>&dp){
        if(idx==s.length())return true;
        if(dp[idx] != -1)return dp[idx];

        for(int i=idx; i<s.length(); i++){
            string temp = s.substr(idx, i-idx+1);
            if(st.find(temp) != st.end() and func(s, i+1, st, dp)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& words) 
    {
        set<string>st;
        vector<int>dp(s.size(), -1);
        for(auto it: words)st.insert(it);
        return func(s, 0, st, dp);
    }
};