class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int n = arr.size();
        int ans=INT_MAX;
        long long sum=0;
        
        for(int i=0; i<n; i++)sum +=arr[i];

        if(sum<x)return -1;
        
        int windowSum=0;
        int start=0, last=n, i=0, j=0;
        while(j<n){
            windowSum += arr[j];
            while(windowSum>sum-x){
                windowSum -= arr[i];
                i++;
            }
            if(windowSum == sum-x){
                ans = min(ans, n-(j-i+1));
            }
            j++;
        }

        return ans==INT_MAX?-1:ans;
    }
};