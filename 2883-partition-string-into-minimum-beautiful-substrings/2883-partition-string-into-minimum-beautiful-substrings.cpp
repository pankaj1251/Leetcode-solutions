class Solution {
public:
    bool isValid(string &s, int i, int j){
        if(s[i]=='0')return false;
        int temp=1, num=0;
        for(int k=j; k>=i; k--){
            if(s[k]=='1')num += temp;
            temp*=2;
        }

        while(num>1){
            if(num%5==0) num /= 5;
            else return false;
        }

        return true;
    }
    int func(string &s, int idx, vector<int> &dp){
        if(idx==s.length())return 0;
        if(dp[idx] != -1)return dp[idx];

        int ans=1e9;
        for(int i=idx; i<s.size(); i++){
            if(isValid(s, idx, i)){
                ans = min(ans, 1 + func(s, i+1, dp));
            }
        }

        return dp[idx] = ans;
    }
    int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        vector<int>dp(n, -1);        
        int ans = func(s, 0, dp);
        return ans==1e9 ? -1 : ans;
    }
};