class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int>dp(n, 1);
        vector<int>hash(n, 0);
        int idx = 0, maxm=1;
        for(int i=0; i<n; i++){
            hash[i]=i;
            for(int prev=0; prev<i; prev++){
                if(arr[i]%arr[prev]==0 and 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i]=prev;
                }
            }
            if(maxm<dp[i]){
                maxm=dp[i];
                idx=i;
            }
        }

        vector<int>lis(maxm);
        int i=1;
        lis[0]=arr[idx];

        while(hash[idx] != idx){
            idx = hash[idx];
            lis[i++]=arr[idx];
        }

        reverse(lis.begin(), lis.end());

        return lis;
    }
};