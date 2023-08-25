class Solution {
public:
    int dfs(vector<vector<int>>&adj, int target, int node, int parent, vector<int>&nums){
        int temp_sum = nums[node];

        for(auto &it: adj[node]){
            if(it != parent){
                int rem = dfs(adj, target, it, node, nums);
                temp_sum += rem;
                if(rem<0)return -1; //for # Case.
            }
        }

        if(temp_sum==target)return 0;
        //# Case
        if(temp_sum > target)return -1;

        return temp_sum;
        
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>>adj(n);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int sum=0;
        for(int i=0; i<n; i++) sum += nums[i];

        for(int i=1; i<=sum; i++){
            if(sum%i==0 )
            {
                int ans = dfs(adj, i, 0, -1, nums);

                if(ans==0){
                    int res = sum/i;
                    return res-1;
                }
            }
        }

        return -1;
    }
};