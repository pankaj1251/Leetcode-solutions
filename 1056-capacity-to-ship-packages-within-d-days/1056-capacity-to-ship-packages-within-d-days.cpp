class Solution {
public:
    int func(vector<int>&arr, int d, int mid){
        int n=arr.size(), c=1, sum=0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum > mid){
                c++;
                sum=arr[i];
            }
        }
        return c;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size();
        long long sum=0;
        int l=INT_MIN;
        //We can set the minimum weight capacity of the ship to the maximum weight of any single package, since the ship must be able to carry at least one package.
        for(int i=0; i<n; i++){l = max(l, arr[i]); sum += arr[i];
}
        int h=sum;
        int ans;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(func(arr, days, mid)<=days){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};