class Solution {
public:
    int mod = 1e9+7;

    int func(int song_idx, int goal_idx, int n, int goal, int k, vector<vector<int>> &dp){

        if(song_idx==0 and goal_idx==0) return 1;
        
        if(song_idx==0 || goal_idx==0)return 0;

        if(dp[song_idx][goal_idx] != -1)return  dp[song_idx][goal_idx];

        long long ans = (long long) func(song_idx - 1, goal_idx - 1, n, goal, k, dp) * (n - song_idx + 1) %mod;

        if(song_idx > k){
            ans +=  (long long) func(song_idx, goal_idx - 1, n, goal, k, dp) * (song_idx - k)%mod;
        }

        return dp[song_idx][goal_idx] = ans%mod;

    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(n+1, vector<int>(goal+1, -1));
        return func(n, goal, n, goal, k, dp);
    }
};