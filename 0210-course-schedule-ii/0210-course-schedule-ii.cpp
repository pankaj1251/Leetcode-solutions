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

    void topoSort(vector<vector<int>>&adj, int node, vector<int>&vis, vector<int>&ans)
    {
        vis[node]=1;
        for(auto &it: adj[node]){
            if(!vis[it]){
                topoSort(adj, it, vis, ans);
            }
        }
        ans.push_back(node);
    }

    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<vector<int>>adj(n);

        for(int i=0; i<arr.size(); i++){
            adj[arr[i][1]].push_back(arr[i][0]);
        }

        vector<int>ans, vis1(n, 0), vis2(n, 0), pathVis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis1[i]) {
                if(isCycle(adj, i, vis1, pathVis))return {};
            }
        }

        for(int i=0; i<n; i++){
            if(!vis2[i]) {
                topoSort(adj, i, vis2, ans);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
}; 