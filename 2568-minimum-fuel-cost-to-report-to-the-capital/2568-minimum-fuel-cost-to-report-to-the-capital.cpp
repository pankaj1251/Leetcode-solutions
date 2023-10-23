class Solution {
public:
    void count_child(vector<vector<int>>&adj, int node, vector<int>&child){
        child[node]=1;

        for(auto &it: adj[node]){
            if(child[it]==0){
                count_child(adj, it, child);
                child[node] += child[it];
            }
        }
        return;
    }


    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>>adj(n+1);

        for(int i=0; i<n; i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }

        vector<int>child(n+1, 0), vis(n+1, 0);

        count_child(adj, 0, child);

        queue<int>Q;
        Q.push(0);
        vis[0]=1;
        long long minfuel=0;

        while(!Q.empty()){
            int node = Q.front();
            Q.pop();

            for(auto &it: adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    int cnt = child[it];
                    minfuel += (cnt/seats);

                    if(cnt%seats!=0)minfuel++;
                    Q.push(it);
                }
            }
        }

        return minfuel;
    }
};