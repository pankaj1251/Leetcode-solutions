class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& arr) {
        vector<vector<int>>adj(n);
        vector<int>out(n);
        for(auto it: arr){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            out[it[0]]++;
            out[it[1]]++;
        }

        int ans=0;
        set<vector<int>>st(arr.begin(), arr.end());

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)continue;
                int f = i;
                int s = j;
                int temp = out[f]+out[s];
                if(st.find({f, s}) != st.end() || st.find({s, f}) != st.end()) temp--;

                ans = max(ans, temp);
            }
        }

        return ans;
    }
};