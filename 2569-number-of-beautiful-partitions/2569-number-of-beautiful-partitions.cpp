class Solution {
public:
    int mod=1e9+7; 
    bool isPrime(int n){
        if(n==2 || n==3 || n==5 || n==7)return true;
        return false;
    }

    int func(string &s, int idx, int k, int minLen, vector<vector<int>> &dp){
        if(idx==s.length() and k==0)return 1;
        if(idx>=s.length() || k<0 || s.length()-idx<minLen)return 0;

        if(dp[idx][k] != -1)return dp[idx][k];
        
        int count=0;
        if(isPrime(s[idx]-'0')){
            for(int i=idx+1; i<s.length(); i++){
                if(!isPrime(s[i]-'0') and i-idx+1>=minLen){
                    count = (count + func(s, i+1, k-1, minLen, dp)%mod)%mod; 
                }
            }
        }
        return dp[idx][k] = count%mod;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return func(s, 0, k, minLength, dp);
    }
};