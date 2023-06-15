class Solution {
public:
    void dfs(vector<vector<int>>&adj, int node, int n, vector<int>&vis, vector<int>&path, vector<vector<int>>&ans){
        vis[node]=1;
        path.push_back(node);
        
        if(node==n-1){
            ans.push_back(path);
            // return;
        }

        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj, it, n, vis, path, ans);
            }
        }
        vis[node]=0;
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>>adj(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<arr[i].size(); j++){
                adj[i].push_back(arr[i][j]);
            }
        }   

        vector<vector<int>>ans;
        vector<int>path, vis(n, 0);

        dfs(adj, 0, n, vis, path, ans);

        return ans;
    }
};