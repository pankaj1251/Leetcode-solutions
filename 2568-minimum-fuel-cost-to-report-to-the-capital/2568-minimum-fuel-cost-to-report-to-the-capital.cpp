class Solution {
public:
    int dfs(vector<vector<int>>&adj, int node, int prev, int seats, long long &ans){
        int people=1;

        for(auto &it : adj[node]){
            if(it==prev)continue;

            people += dfs(adj, it, node, seats, ans);
        }

        if(node != 0)
            ans = ans + (people-1)/seats + 1;  // +1 because you are also including yourself.
            
        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<vector<int>>adj(n);

        for(auto it: roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        long long ans=0;
        dfs(adj, 0, -1, seats, ans);

        return ans;
    }
};