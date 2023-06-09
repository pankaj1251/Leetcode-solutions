class Solution {
public:

    bool isCycle(vector<vector<int>>&adj, int node, vector<int> &vis, vector<int>&pathVis, vector<int>&ans){
        
        vis[node]=1;
        pathVis[node]=1;

        for(auto &it: adj[node]){
            if(!vis[it]){
                if(isCycle(adj, it, vis, pathVis, ans))return true;
            }
            else{
                if(pathVis[it]) return true;
                
            }
        }
        ans.push_back(node);
        pathVis[node]=0;
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<vector<int>>adj(n);

        for(int i=0; i<arr.size(); i++){
            adj[arr[i][1]].push_back(arr[i][0]);
        }

        vector<int>ans, vis(n, 0), pathVis(n, 0);

        for(int i=0; i<n; i++){
            if(!vis[i]) {
                if(isCycle(adj, i, vis, pathVis, ans)==true)return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
}; 