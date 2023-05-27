class Solution {
public:
    void dfs(unordered_map<string, vector<string>>&adj, string &email, unordered_set<string> &vis, vector<vector<string>> &ans){
        vis.insert(email);
        ans.back().push_back(email);
        for(auto &adjEmail: adj[email]){
            if(vis.find(adjEmail) == vis.end()){
                dfs(adj, adjEmail, vis, ans);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        int n = arr.size();      
        unordered_map<string, vector<string>>adj(n);
        unordered_set<string>vis;
        vector<vector<string>>ans;

        for(int i=0; i<n; i++){
            for(int j=1; j<arr[i].size()-1; j++){
                adj[arr[i][j]].push_back(arr[i][j+1]);
                adj[arr[i][j+1]].push_back(arr[i][j]);
            }
        }

        for(auto &it: arr){
            if(vis.find(it[1]) == vis.end()){
                ans.push_back({it[0]}); 
                dfs(adj, it[1], vis, ans);
                sort(ans.back().begin()+1, ans.back().end());
            }
        }

        return ans;
    }
};