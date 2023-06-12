class Solution {
public:
    bool isCycle(vector<vector<int>>&adj, vector<int>&vis, int child, int parent){
        if(vis[child])return true;

        vis[child]=1;

        for(auto it: adj[child]){
            if(it != parent and isCycle(adj, vis, it, child)) return true;;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>>adj(n+1);

        for(auto edge: arr){ //as we want last edge added in arr thats why we are doing this trick.
            vector<int>vis(n+1, 0);
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            if(isCycle(adj, vis, edge[0], edge[1])){
                return edge;
            }
        }
        return {};
    }
};