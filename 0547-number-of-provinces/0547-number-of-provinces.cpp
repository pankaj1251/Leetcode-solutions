class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>&vis, int node){
        vis[node] = true;

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=true;
                dfs(adj, vis, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>>adj(n, vector<int>());

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j and arr[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int>vis(n, false); 
        int ans=0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                ans++;
            }    
        }

        return ans;
    }
};