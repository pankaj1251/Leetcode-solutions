class Solution {
public:
    bool isCycle(vector<vector<int>>&adj, int node, vector<int> &vis, vector<int>&pathVis){
        vis[node]=1;
        pathVis[node]=1;

        for(auto &it: adj[node]){
            if(!vis[it]){
                if(isCycle(adj, it, vis, pathVis))return true;
            }
            else{
                if(pathVis[it]) return true;
                
            }
        }

        pathVis[node]=0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<vector<int>>adj(n);

        for(int i=0; i<arr.size(); i++){
            adj[arr[i][0]].push_back(arr[i][1]);
        }

        vector<int>vis(n, 0);
        vector<int>pathVis(n, 0);
        for(int i=0; i<n; i++)
            if(!vis[i])
                if(isCycle(adj, i, vis, pathVis))return false;

        return true;
    }
};