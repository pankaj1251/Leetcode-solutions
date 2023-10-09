class Solution {
public:

    int func(vector<pair<int, pair<int, int>>> &arr, vector<int>& startTime, int idx, vector<int> &dp)
    {
        if(idx==arr.size())return 0;

        if(dp[idx] != -1)return dp[idx];

        int inc=0, exc=0;
        int next_idx = lower_bound(startTime.begin(), startTime.end(), arr[idx].second.first)-startTime.begin();
            
        inc = arr[idx].second.second + func(arr, startTime, next_idx, dp);

        exc = func(arr, startTime, idx+1, dp);

        return dp[idx] = max(inc, exc);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int>dp(n+1, -1);
        
        vector<pair<int, pair<int, int>>>arr;
        for(int i=0; i<n; i++){
            arr.push_back({startTime[i], {endTime[i], profit[i]}});
        }

        sort(arr.begin(), arr.end());
        sort(startTime.begin(), startTime.end());
        int ans=func(arr, startTime, 0, dp);

        return ans;
    }
};