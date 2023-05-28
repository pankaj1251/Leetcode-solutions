class Solution {
public:
    int func(vector<int>& arr, int st, int en, int arr_start, int arr_end, vector<vector<int>>&dp)
    {
        if(arr_start > arr_end)return 0;

        if(dp[arr_start][arr_end] != -1)return dp[arr_start][arr_end];

        int minimum = INT_MAX;

        for(int i = arr_start; i <= arr_end; i++)
        {
            minimum = min(minimum, (en-st) + func(arr, st, arr[i], arr_start, i-1, dp) + 
                                             func(arr, arr[i], en, i+1, arr_end, dp));
        }

        return dp[arr_start][arr_end] = minimum;
    }
    
    int minCost(int n, vector<int>& arr) 
    {
        int sz = arr.size();
        //If all elements are easily sorted, then find the cuts from the st to the en.
        //Otherwise, if the vector is not sorted, traversing the entire vector becomes a time-consuming task, which is wasteful.
        sort(arr.begin(), arr.end());
        vector<vector<int>>dp(sz, vector<int>(sz, -1));
        int ans;
        ans = func(arr, 0, n, 0, sz-1, dp);

        return ans;
    }
};