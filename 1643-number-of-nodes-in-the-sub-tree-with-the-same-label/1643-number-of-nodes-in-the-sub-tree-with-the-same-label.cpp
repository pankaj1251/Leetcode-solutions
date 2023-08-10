class Solution {
public:
    vector<int>dfs(int prev, int node, vector<vector<int>> &adj, string &str, vector<int> &ans)
    {
        vector<int>temp(26);
        // init the current label
        temp[str[node]-'a']=1;

        for(auto &it: adj[node])
        {
            if(prev != it)
            {
                vector<int>res = dfs(node, it, adj, str, ans);
                for(int i=0; i<26; i++)
                {
                    temp[i] += res[i];
                }
            }
        }

        ans[node] = temp[str[node]-'a'];
        return temp;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& arr, string labels) {
        vector<vector<int>>adj(n);

        for(auto &it: arr){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>ans(n);

        dfs(-1, 0, adj, labels, ans);

        return ans;
    }
};