class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int goal) {
        int n = arr.size();
        map<int, int>umap;
        vector<int>prefix(n);
        prefix[0]=arr[0];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1]+arr[i];
        }

        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(prefix[i]==goal)ans++;
            //Assume you are at index k and "k>goal" so we have to find subarray with sum as goal.
            if(umap.find(prefix[i]-goal) != umap.end()) ans += umap[prefix[i]-goal];

            umap[prefix[i]]++;
        }

        return ans;
    }
};