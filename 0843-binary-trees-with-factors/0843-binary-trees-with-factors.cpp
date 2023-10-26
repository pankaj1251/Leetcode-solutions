class Solution {
public:
    const int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        unordered_map<int, long long>umap;

        umap[arr[0]] = 1;

        for(int i=1; i<n; i++){
            long long cnt=1;
            for(auto it: umap){
                int elem = it.first;
                if(arr[i]%elem==0 and umap.count(arr[i]/elem)){
                    cnt += umap[elem] * umap[arr[i]/elem];
                }
            }

            umap[arr[i]]=cnt;
        }

        int ans=0;
        for(auto &it: umap){
            ans = (ans + it.second) % mod;
        }

        return ans;
    }
};