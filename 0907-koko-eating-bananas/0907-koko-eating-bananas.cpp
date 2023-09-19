class Solution {
public:
    long long func(vector<int>&arr, int idx){
        long long ans=0, n = arr.size();
        for(int i=0; i<n; i++){
            int temp= ceil(arr[i]/double(idx));
            ans += temp;
        }

        return ans;
    }
    int minEatingSpeed(vector<int>& arr, int target) {
        int n = arr.size();
        int l=1, h=0;
        for(int i=0; i<n; i++){
            h=max(h, arr[i]);
        }
        int ans=0;
        while(l<=h){
            int mid = l + (h-l)/2;
            long long hoursToEat = func(arr, mid);
            if(hoursToEat<=target){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }

        return ans;
    }
};