class Solution {
public:
    int numberOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size(), i=0, j=0, ans=0;
        int c=0;
        for(int i=0; i<n;i++){
            if(arr[i]%2==0){
                arr[i]=0;
            }
            else arr[i] = 1;
        }

        vector<int>prefix(n+1);
        prefix[0]=arr[0];

        for(int i=1; i<n;i++){
            prefix[i] = arr[i]+prefix[i-1];
        }

        unordered_map<int, int>umap;
        while(j<n){
            if(prefix[j] == k)ans++;
            if(umap.find(prefix[j]-k) != umap.end())ans += umap[prefix[j]-k];

            umap[prefix[j]]++;
            j++;
        }

        return ans;
    }
};