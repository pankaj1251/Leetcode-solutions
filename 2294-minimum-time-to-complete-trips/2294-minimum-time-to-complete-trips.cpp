class Solution {
public:
    long long func(vector<int>&time, long long mid){
        int n = time.size();
        long long ans=0;
        for(int i=0; i<n; i++){
            ans += (mid/time[i]);
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long l=1, h=1e14;
        while(l<=h){
            long long mid = l+(h-l)/2;
            long long trips = func(time, mid);
            if (trips<totalTrips)l=mid+1;
            else h=mid-1;
        }
        return l;
    }
};