class Solution {
public:
    void dfs(vector<vector<int>>&adj, int node, vector<int>& quiet, int &temp, int &ans,vector<int>& vis){
        vis[node]=1;
        if(temp>quiet[node]){
            ans=node;
            temp = quiet[node];
        }

        for(auto &it: adj[node]){
            if(!vis[it]){
                dfs(adj, it, quiet, temp, ans, vis);
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& arr, vector<int>& quiet) {
        int n=quiet.size();
        vector<int>outdegree(n, 0);
        vector<vector<int>>adj(n);
        for(int i=0; i<arr.size(); i++){
            adj[arr[i][1]].push_back(arr[i][0]);
            outdegree[arr[i][1]]++;
        }
        queue<int>Q;
        vector<int>ans(n);

        for(int i=0; i<n; i++){
            if(outdegree[i]!=0)Q.push(i);
            else ans[i] = i;
        }

        for(auto it: outdegree)cout<<it<<" ";
        cout<<endl;
        while(!Q.empty()){
            int node=Q.front();
            Q.pop();
            vector<int>vis(n, 0);
            int temp=INT_MAX;
            int res=-1;
            dfs(adj, node, quiet, temp, res, vis);
            ans[node]=res;
        }

        return ans;
    }
};