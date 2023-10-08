
#define ll long long
class Solution {
public:
    ll func(vector<int>& arr1, vector<int>& arr2, int i, int j, int n, int m, vector<vector<ll>> &dp){
        if(i==n || j==m)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        return dp[i][j] = max(((ll) arr1[i]*arr2[j]) + func(arr1, arr2, i+1, j+1, n, m, dp), 
                          max(func(arr1, arr2, i+1, j, n, m, dp), func(arr1, arr2, i, j+1, n, m, dp)));
    }

    int maxDotProduct(vector<int>& arr1, vector<int>& arr2) 
    {
        int n = arr1.size(), m=arr2.size();
        vector<vector<ll>>dp(n+1, vector<ll>(m+1, -1));

        ll ans = func(arr1, arr2, 0, 0, n, m, dp);

        if(ans==0){
            int a = *max_element(arr1.begin(), arr1.end());
            int b = *min_element(arr1.begin(), arr1.end());
           
            int c = *max_element(arr2.begin(), arr2.end());
            int d = *min_element(arr2.begin(), arr2.end());

            return max(a*d, b*c);
        }

        return ans;
    }
};