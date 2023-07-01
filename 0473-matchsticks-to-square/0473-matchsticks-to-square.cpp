class Solution {
public:
    int sum;
    bool dfs(vector<int>& arr, int idx, int k, int curr_sum, vector<int>& vis){
        if(k==1)return true;

        if(curr_sum == sum/4)return dfs(arr, 0, k-1, 0, vis);

        for(int i=idx; i<arr.size(); i++){
            if(vis[i]==1 || curr_sum + arr[i] > sum/4)continue;

            vis[i]=1;
            if(dfs(arr, i+1, k, curr_sum + arr[i], vis))return true;
            vis[i]=0;
        }

        return false;
    }

    bool makesquare(vector<int>& arr) {
        sum=0;
        int n = arr.size();
        for(int i=0; i<n; i++)sum += arr[i];
        if(n<4 || sum%4!=0)return false;
        vector<int> vis(n, 0);

        return dfs(arr, 0, 4, 0, vis);
    }
};