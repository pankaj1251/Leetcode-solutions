class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)return {};
        if(n==1)return {0};
        
        vector<vector<int>>adj(n);
        vector<int>vis(n, 0);
        vector<int>indegree(n, 0);

        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        
        queue<int>Q;
        for(int i=0; i<n; i++){
            if(indegree[i]==1)Q.push(i); //all leaf nodes.
        }
        vector<int>ans;
        while(!Q.empty()){
            ans.clear(); //we are doing this to store our final answer which will come at the end when there are <=2 nodes are present in queue which is our answer. -  we dont nwwd other values that come before while we traverse.

            int sz = Q.size();
            while(sz--){
                int node = Q.front();
                Q.pop();

                ans.push_back(node);

                for(auto &it: adj[node]){
                    indegree[it]--;
                    if(indegree[it]==1)Q.push(it);
                }
            }
        }
        return ans;
    }
};