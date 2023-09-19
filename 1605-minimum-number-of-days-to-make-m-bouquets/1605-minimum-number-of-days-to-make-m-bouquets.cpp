class Solution {
public:
    bool func(vector<int>&arr, int m, int k, int mid){
        int c=0, ans=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]<=mid)c++;
            else c=0;

            if(c==k){c=0, ans++;}
            if(ans==m)return true;
        }

        return false;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if(n==0 || m==0 || k==0)return 0;

        // long long p = m*k;
        if(n/k<m)return -1;
        
        int h=INT_MIN, l=INT_MAX;

        for(int i=0; i<n; i++){
            l = min(l, arr[i]);
            h = max(h, arr[i]);
        }

        while(l<=h){
            int mid = l + (h-l)/2;
            if(func(arr, m, k, mid)){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return l;
    }
};