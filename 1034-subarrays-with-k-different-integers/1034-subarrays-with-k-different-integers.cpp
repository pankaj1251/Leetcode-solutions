class Solution {
public:
    int atMost(vector<int> &arr, int k){
int n = arr.size();
        int i=0, ans=0, unique=0;
        unordered_map<int, int>umap;

        for(int j=0; j<n; j++)
        {
            if(umap[arr[j]]==0)unique++;

            umap[arr[j]]++;

            while(unique>k){
                umap[arr[i]]--;
                if(umap[arr[i]] == 0)unique--;
                i++;
            }
            ans += j-i+1;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return atMost(arr, k) - atMost(arr, k-1);
    }
};