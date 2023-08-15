class Solution {
public:
    //print LIS.
    int lengthOfLIS(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int>dp(n, 1), hash(n, 0);
        int maxm = 1, lastIndex=0;

        for(int i=0; i<n; i++)
        {
            hash[i]=i;
            for(int prev=0; prev<i; prev++)
            {
                if(arr[prev]<arr[i] and 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxm){
                maxm=dp[i];
                lastIndex=i;
            }
        }

        vector<int> lis(maxm);
        lis[0] = arr[lastIndex];
        int idx=1;
        while(hash[lastIndex] != lastIndex){
            lastIndex=hash[lastIndex];
            lis[idx++] = arr[lastIndex];
        }

        reverse(lis.begin(), lis.end());
        for(auto &it: lis)cout<<it<<" ";
        cout<<"\n";

        return maxm;
    }
};