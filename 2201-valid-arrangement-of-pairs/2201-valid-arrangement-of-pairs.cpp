class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, int node, vector<vector<int>> &ans)
    {
        while(adj[node].size()){
            int next = adj[node].back();
            adj[node].pop_back();
            dfs(adj, next, ans);
            ans.push_back({node, next});
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>>umap;
        unordered_map<int, int>indegree;

        for(int i=0; i<n; i++){
            umap[arr[i][0]].push_back(arr[i][1]);
            indegree[arr[i][0]]++; //for finding the first element.
            indegree[arr[i][1]]--;
        }

        int start = -1;
        for(auto it: indegree){
            if(it.second>0)start = it.first;
        }

        if(start==-1)start = arr[0][0];
        
        vector<vector<int>>ans;
        dfs(umap, start, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};