class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>rev_adj(n);
        vector<int>indegree(n);

        int i=0;
        //we are reversing the adj list as we only need to travel from source(1) to distination(n)
        //as toposort has everyting in the sense of indegree
        //as n will have outdegree 0 so if we reverse the adj list n will have indegree 0 (as we need to do toposort in terms of indegree.)
        for(auto &g: graph){
            for(auto it: g){
                rev_adj[it].push_back(i);
                indegree[i]++;
            }
            i++;
        }

        queue<int>Q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0)Q.push(i);
        }

        vector<int>ans;

        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            ans.push_back(node);

            for(auto it: rev_adj[node]){
                indegree[it]--;
                if(indegree[it]==0)Q.push(it);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;

    }
};