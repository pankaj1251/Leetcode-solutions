class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        unordered_map<int, int>umap;
        int ans = INT_MAX;
        int max_freq = 0;

        for(int i=0; i<n; i++){
            int temp = nums[i]%space;
            umap[temp]++;
            max_freq = max(max_freq, umap[temp]);
        }

        for(int i=0; i<n; i++){
            int temp = nums[i]%space;
            if(umap[temp] == max_freq)ans= min(ans, nums[i]);
        }

        return ans;
    }
};