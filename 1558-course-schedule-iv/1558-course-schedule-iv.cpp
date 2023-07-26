class Solution {
public:
    void dfs(vector<int> adj[], int src, int& dest, bool& temp, vector<bool>& vis) {
        if(vis[src]) return;
        vis[src] = true;
        
        if(src == dest) {
            temp = true;
            return;
        }
        
        for(auto it : adj[src]) 
            dfs(adj, it, dest, temp, vis);
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& que) {
        vector<int> adj[n];
        
        for(auto it : pre) 
            adj[it[0]].push_back(it[1]);
        
        int sz = que.size();
        vector<bool> ans(sz);
        
        for(int i=0;i<sz;i++) {
            int src = que[i][0];
            int dest = que[i][1];
            
            bool temp = false;
            vector<bool> vis(n, false);
            dfs(adj, src, dest, temp, vis);
            ans[i] = temp;
        }
        
        return ans;
    }
};