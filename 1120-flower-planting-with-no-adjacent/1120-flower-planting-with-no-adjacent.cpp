class Solution {
public:
    void func(vector<vector<int>> &adj, int idx, vector<int>&vis){

        for(int i=1; i<=4; i++){
            bool flag = false;
            for(auto &it: adj[idx]){
                if(vis[it]==i){
                    flag=true;
                    break;
                }
            }

            if(flag==false){
                vis[idx]=i;
            }
        }
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& arr) {
        vector<vector<int>>adj(n+1);

        for(auto it: arr){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>ans(n+1);
        vector<int>vis(n+1);

        for(int i=1; i<=n; i++){
            if(vis[i] != -1){
                func(adj, i, vis);
            }
        }

        vis.erase(vis.begin());
        return vis;
    }
};