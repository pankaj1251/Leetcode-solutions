class Solution {
public:
    void dfs(vector<vector<int>> &adj, int i, vector<int> &vis, int &ans){
        vis[i]=1;
        ans++;

        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(adj, it, vis, ans);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>>adj(n);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)continue;

                long long x1 = abs((long long) arr[i][0] - (long long) arr[j][0]);
                long long y1 = abs((long long) arr[i][1] - (long long) arr[j][1]);
                long long r = arr[i][2];
            
                if((x1*x1) + (y1*y1) <= r*r)
                {
                    adj[i].push_back(j);
                }
            }
        }

        int ans=0;
        for(int i=0; i<n; i++)
        {
            int c=0;
            vector<int>vis(n, 0);
            dfs(adj, i, vis, c);
            ans = max(ans, c);
        }

        return ans;
    }
};