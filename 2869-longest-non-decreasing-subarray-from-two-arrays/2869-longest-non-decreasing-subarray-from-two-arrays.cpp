class Solution {
public:
    int func(vector<int>& arr1, vector<int>& arr2, int i, int prev, int n, vector<vector<int>> &dp){
        if(i>=n)return 0;
        if(dp[i][prev] != -1)return dp[i][prev];
        int ans=0;
        if(prev==0){ //no element is taken from both arrays.
            int not_take = func(arr1, arr2, i+1, 0, n, dp); //take no elements from any array.
            int take1 = 1+ func(arr1, arr2, i+1, 1, n, dp); //take element from arr1
            int take2 = 1+ func(arr1, arr2, i+1, 2, n, dp); //take element from arr2
            ans = max(not_take, max(take1, take2));
        }
        else{
            if(prev==1){  // prev array is nums1
                if(arr1[i-1] <= arr1[i]) ans = max(ans, 1+func(arr1, arr2, i+1, 1, n, dp));
                if(arr1[i-1] <= arr2[i])  ans = max(ans, 1+func(arr1, arr2, i+1, 2, n, dp));
            }
            else if(prev==2){ // prev array is num2 
                if(arr2[i-1] <= arr1[i]) ans = max(ans, 1+func(arr1, arr2, i+1, 1, n, dp));
                if(arr2[i-1] <= arr2[i]) ans = max(ans, 1+func(arr1, arr2, i+1, 2, n, dp));
            }
        }

        return dp[i][prev] = ans;
    }
    int maxNonDecreasingLength(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int>ans;
        vector<vector<int>>dp(n+1, vector<int>(3, -1));
        return func(arr1, arr2, 0, 0, n, dp);
    }
};