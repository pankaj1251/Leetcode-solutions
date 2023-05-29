class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>>adj;

public:
    void dfs(string node, vector<string> &ans)
    {
        auto &it = adj[node];

        while(!it.empty()){
            string temp = it.top();
            it.pop();
            dfs(temp, ans);
            ans.push_back(temp);
        }
        
    }

    vector<string> findItinerary(vector<vector<string>>& arr) {
        int n = arr.size();
        vector<string>ans;

        for(auto &it: arr){
            adj[it[0]].push(it[1]);
        }

        dfs("JFK", ans);
        ans.push_back("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};