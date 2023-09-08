class Solution {
public:
    //k eggs, n floors
    int func(int k, int n, vector<vector<int>> &dp)
    {
        if(n==0 || n==1) return n;
        if(k==1)return n;
        if(dp[k][n] != -1)return dp[k][n];

        int ans = INT_MAX;

        int l=1, h=n, temp=0;

        while(l<=h){
            int mid = (l+h)/2;
            int broken = func(k-1, mid - 1, dp); //egg broken check for down floors of mid
            int not_broken = func(k, n - mid, dp); // not broken check for up floors of mid

            temp = 1 + max(broken, not_broken);

            if(broken < not_broken) l=mid+1; //since right is more than left and we need more in worst case 
            else h=mid-1;

            ans = min(ans, temp);  //store minimum attempts
        }

        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return func(k, n, dp);
    }
};