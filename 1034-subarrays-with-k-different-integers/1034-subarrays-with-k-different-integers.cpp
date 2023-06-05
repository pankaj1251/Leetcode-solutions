class Solution {
public:
    int atMost(vector<int> &arr, int k)
    {
        int n = arr.size();
        int i=0, j=0, ans=0;
        unordered_map<int, int>umap;

        while(j<n)
        {
            umap[arr[j]]++;

            while(umap.size()>k){
                umap[arr[i]]--;
                if(umap[arr[i]]==0)umap.erase(arr[i]);
                i++;
            }

            ans +=j-i+1;
            j++;
        }

        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return atMost(arr, k) - atMost(arr, k-1);
    }
};