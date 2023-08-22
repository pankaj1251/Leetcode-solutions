class Solution {
public:
    int longestEqualSubarray(vector<int>& s, int k) {
        int i=0, j=0, n = s.size();
        unordered_map<int, int>umap;
        int ans=0;
        int maxCount=0;
        while(j<n){
            umap[s[j]]++;
            
            maxCount = max(maxCount, umap[s[j]]);

            while(j - i - maxCount >= k){
                umap[s[i]]--;
                i++;
            }
            ans = max(ans, maxCount);
            j++;
        }

        return ans;
    }
};