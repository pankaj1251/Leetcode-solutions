class Solution {
public:
    bool isValid(vector<int>&arr, int low, int high, int m){
        int sum=0;
        for(int i=low; i<=high; i++){
            sum += arr[i];
        }
        return (sum>=m);
    }

    bool func(vector<int>&arr, int low, int high, int m, vector<vector<int>> &dp)
    {
        if(low==high)return true;
        if(!isValid(arr, low, high, m))return false;
    
        if(dp[low][high] != -1)return (dp[low][high] == 1 ? true : false);

        bool ans=false;
        for(int idx=low; idx<high; idx++){  //idx<high bcz in "right" we are doing idx+1.
            bool left = func(arr, low, idx, m, dp);
            bool right = func(arr, idx+1, high, m, dp);

            if(left and right){ans=true;break;}
        }

        return dp[low][high] = ans;
    }

    bool canSplitArray(vector<int>& arr, int m) {
        int n=arr.size();
        if(n<=2)return true;
        
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return func(arr, 0, n-1, m, dp);
    }
};