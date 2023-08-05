class Solution {
public:
    int func(vector<int>& arr, int i, vector<int> &vis){
        if(vis[i]==1)return 0;
        vis[i]=1;

        return 1 + func(arr, arr[i], vis);
    }
    int arrayNesting(vector<int>& arr) {
        int ans = 1, n = arr.size();
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans = max(ans, func(arr, i, vis));
            }
        }

        return ans;
    }
};