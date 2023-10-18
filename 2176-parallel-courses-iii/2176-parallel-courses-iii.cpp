class Solution {
public:
    int func(vector<vector<int>> &adj, int node, vector<int>&time, vector<int>&dp){
        if(dp[node] != -1)return dp[node];

        //If the course has no prerequisites, its time is simply its own duration.
        if(adj[node].empty()){
            dp[node]=time[node];
            return dp[node];
        }

        int ans=0;
        for(auto &it: adj[node]){
            ans = max(ans, func(adj, it,time, dp));
        }

        dp[node] = ans + time[node];

        return dp[node];
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n);

        for(auto &it: relations){
            adj[it[0]-1].push_back(it[1]-1);
        }    

        vector<int>dp(n+1, -1);
        int ans=0;
        for(int i=0; i<n; i++){
            ans = max(ans, func(adj, i, time, dp));
        }

        return ans;
    }
};