class Solution {
public:
    bool func(vector<int>&arr, int idx, int gap, vector<vector<int>> &dp)
    {
        if(idx==arr.size()-1)return true;

        if(dp[idx][gap] != -1)return dp[idx][gap];

        for(int i=idx+1; i<arr.size(); i++)
        {
            if(arr[i]-arr[idx]>=gap - 1 and arr[i]-arr[idx] <= gap+1){
                if(func(arr, i, arr[i]-arr[idx], dp)) return dp[idx][gap] = true;
            }
        }        
        return dp[idx][gap] = false;
    }
    bool canCross(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return func(arr, 0, 0, dp);
    }
};