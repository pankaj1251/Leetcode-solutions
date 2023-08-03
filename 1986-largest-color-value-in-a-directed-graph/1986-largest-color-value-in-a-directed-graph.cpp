class Solution {
public:
    unordered_map<int, unordered_map<char, int>>dp;
    int ans=0;
    pair<unordered_map<char, int>, bool> dfs(vector<vector<int>> &adj, int i, vector<int> &vis, vector<int> &pathVis, string &colors){

        vis[i]=1;
        pathVis[i]=1;
        unordered_map<char, int>umap;

        for(auto &it: adj[i]){
            if(!vis[it]){
                auto temp = dfs(adj, it, vis, pathVis, colors);

                if(temp.second)return {umap, true};

                for(auto xx: temp.first){
                    umap[xx.first] = max(umap[xx.first], xx.second);
                }
            }
            else {
                if(pathVis[it])return {umap, true};
                for(auto xx: dp[it]){
                    umap[xx.first] = max(umap[xx.first], xx.second);
                }
            }

        }

        pathVis[i]=0;
        umap[colors[i]]++;
        dp[i]=umap;

        return {umap, false};
    }
    int largestPathValue(string colors, vector<vector<int>>& arr) {
        int n = colors.size();
        vector<vector<int>>adj(n);

        for(auto it: arr){
            adj[it[0]].push_back(it[1]);
        }

        vector<int>vis(n, 0), pathVis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                auto temp = dfs(adj, i, vis, pathVis, colors);
                if(temp.second)return -1;
                
                for(auto xx: temp.first){
                    ans = max(ans, xx.second);
                }
            }
        }
        return ans;
    }
};