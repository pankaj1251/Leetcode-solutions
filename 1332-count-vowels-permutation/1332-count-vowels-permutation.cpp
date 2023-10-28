class Solution {
    const int mod = 1e9+7;
    const unordered_map<char, vector<char>> mapping{
        {'s', {'a', 'e', 'i', 'o', 'u'}}, //at start any vowel is allowed.
        { 'a', {'e'}                   },
        { 'e', {'a', 'i'}              },
        { 'i', {'a', 'e', 'o', 'u'}    }, 
        { 'o', {'i', 'u'}              },
        { 'u', {'a'}                   }
    };

    unordered_map<char, vector<int>>dp;

public:
    
    int func(int n, char prev){
        if(n==0) return 1;

        if(dp[prev][n])return dp[prev][n];

        for(auto &it: mapping.at(prev)){
            dp[prev][n] = (dp[prev][n] + func(n-1, it))%mod;
        }
        return dp[prev][n];
    }

    int countVowelPermutation(int n) {
        dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n+1);

        return func(n, 's');    
    }
};