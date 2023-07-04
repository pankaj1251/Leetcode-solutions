class Solution {
public:
    bool func(vector<int>& arr, int idx, int curr_sum, int sum, int k, vector<int>&vis){
        if(k==1)return true;
        if(idx>=arr.size())return false;
        
        if(curr_sum==sum)
            return func(arr, 0, 0, sum, k-1, vis);
        

        for(int i=idx; i<arr.size(); i++)
        {
            if(vis[i] || curr_sum + arr[i] > sum)continue;
            
            vis[i]=1;
            if(func(arr, i+1, curr_sum + arr[i], sum, k, vis))return true;;
            vis[i]=0;
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int sum=0;
        int n = arr.size();

        for(int i=0; i<n; i++)sum += arr[i];

        if(sum % k != 0 || n<k)return false;
       
        vector<int>vis(n, 0);
        return func(arr, 0, 0, sum/k, k, vis);
    }
};