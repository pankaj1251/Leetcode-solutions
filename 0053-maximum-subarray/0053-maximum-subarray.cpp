class Solution {
public:
    vector<int>pre, suf;
    int func(vector<int>&arr, int L, int R){
        if(L==R)return arr[L];
        int mid = (L+R)/2;

        return max({func(arr, L, mid), func(arr, mid+1, R), pre[mid] + suf[mid+1]});
    }
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        pre=suf=arr;

        for(int i=1; i<n; i++){
            pre[i] += max(0, pre[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            suf[i] += max(0, suf[i+1]);
        }

        return func(arr, 0, n-1);
    }   
};