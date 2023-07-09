class Solution {
public:
    long long putMarbles(vector<int>& arr, int k) {
        int n = arr.size();

        long long maxm=0, minm=0;
        k--;
        vector<long long>ans;

        for(int i=1; i<n; i++){
            ans.push_back(arr[i]+arr[i-1]);
        }
        
        sort(ans.begin(), ans.end());
        int n1=ans.size();
        
        for(int i=0; i<k; i++){
            minm += ans[i];
            maxm += ans[n1-1-i]; 
        }

        return maxm-minm;
    }
};