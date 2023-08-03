class Solution {
public:

    int largestPathValue(string colors, vector<vector<int>>& arr) {
        int n = colors.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n, 0);
        for(auto it: arr){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        vector<int>vis(n, 0);
        vector<vector<int>> counts(n, vector<int>(26, 0)); //to count max no of all colors from source to that point.

        queue<int>Q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0)Q.push(i);
        }

        for(int i=0; i<n; i++){
            counts[i][colors[i]-'a']++; //for color of every node of '"colors"'.
        }

        int ans=0;
        int visited = 0;

        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            visited++;

            for(auto it: adj[node]){
                for(int i=0; i<26; i++){
                    counts[it][i] = max(counts[it][i], counts[node][i] + (colors[it]-'a'==i?1:0));
                }
                indegree[it]--;

                if(indegree[it]==0)Q.push(it);
            }

            ans = max(ans, *max_element(counts[node].begin(), counts[node].end()));
        }

        return visited==n? ans : -1; //if visited != n then there is cycle is present. 
    }
};