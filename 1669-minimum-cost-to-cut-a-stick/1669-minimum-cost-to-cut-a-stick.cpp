class Solution {
public:
    int func(vector<int>& arr, int start, int end, int i, int j, vector<vector<int>>&dp)
    {
        if(i>j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        
        int minimum = INT_MAX;
        for(int idx = i; idx<=j; idx++){
            minimum = min(minimum, (end-start) + func(arr, start, arr[idx], i, idx-1, dp) + func(arr, arr[idx], end, idx+1, j, dp));
        }

        return dp[i][j] = minimum;
    }
    int minCost(int n, vector<int>& arr) {
        int sz = arr.size();
        //If all elements are easily sorted, then find the cuts from the start to the end.
        //Otherwise, if the vector is not sorted, traversing the entire vector becomes a time-consuming task, which is wasteful.
        sort(arr.begin(), arr.end());
        vector<vector<int>>dp(sz, vector<int>(sz, -1));
        int ans;
        ans = func(arr, 0, n, 0, sz-1, dp);

        return ans;
    }
};