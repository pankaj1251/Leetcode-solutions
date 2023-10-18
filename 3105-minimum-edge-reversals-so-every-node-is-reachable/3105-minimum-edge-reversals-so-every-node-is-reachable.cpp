class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> revAdj;
          //node parent dist
    map<pair<int, int>, int>dp;

    int dfs(int node, int parent){
        int ans=0;

        if(dp.find({node, parent}) != dp.end())
            return dp[{node, parent}];

        for(auto &it: adj[node]){
            if(it != parent){
                ans += dfs(it, node);
            }
        }
        
        for(auto &it: revAdj[node]){
            if(it != parent){
                ans += (1 + dfs(it, node));
            }
        }

        return dp[{node, parent}] = ans;
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n);
        revAdj = vector<vector<int>>(n);

        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            revAdj[it[1]].push_back(it[0]);
        } 

        vector<int>ans;

        for(int i=0; i<n; i++){
            ans.push_back(dfs(i, -1));
        }

        return ans;
    }
};