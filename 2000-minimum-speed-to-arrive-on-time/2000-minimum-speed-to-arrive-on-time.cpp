class Solution {
public:
    bool func(vector<int> &arr, int v, double hour){
        double ans=0;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            double temp = (double) arr[i]/v;
            if(i==n-1)ans += temp;
            else ans += ceil(temp);
            if(ans>hour)return false;
        }

        return ans<=hour;
    }

    int minSpeedOnTime(vector<int>& arr, double hour) {
        int i=1, j=1e7, ans=-1;

        while(i<=j){
            int mid = (i+j)/2;
            if(func(arr, mid, hour)){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }

        return ans;
    }
};