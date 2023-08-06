class Solution {
public:
    int mod = 1e9+7;
    int func(int goal_idx, int song_idx, int n, int goal, int k, vector<vector<int>> &dp){
        if(song_idx>n || goal_idx>goal)return 0;
        if(song_idx==n and goal_idx==goal)return 1;

        if(dp[song_idx][goal_idx] != -1) return dp[song_idx][goal_idx];

        long long ans = (long long) func(goal_idx+1, song_idx+1, n, goal, k, dp)*(n-song_idx)%mod;
        
        if(song_idx > k){
            ans += (long long) func(goal_idx+1, song_idx, n, goal, k, dp)*(song_idx-k)%mod;
        }

        return dp[song_idx][goal_idx] = ans%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(n+1, vector<int>(goal+1, -1));

        return func(0, 0, n, goal, k, dp)%mod;
    }
};