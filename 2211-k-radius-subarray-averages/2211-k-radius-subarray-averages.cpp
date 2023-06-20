class Solution {
public:
    vector<int> getAverages(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>ans(n, -1);
        int i=0, j=0;
        long long sum = 0;

        if(2*k+1 > n)return ans;
        if(k==0)return arr;
        
        while(j<2*k+1){
            sum = sum + arr[j];
            j++;
        }

        int idx=k;
        ans[idx]=sum/(2*k+1);
        
        while(j<n){
            idx++;
            sum -= arr[i];
            sum += arr[j];
            ans[idx]=sum/(2*k+1);
            j++;
            i++;
        }

        return ans;
    }
};