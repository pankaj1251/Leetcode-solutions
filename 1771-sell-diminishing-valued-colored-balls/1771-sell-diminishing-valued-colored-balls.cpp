class Solution {
public:
    int mod = 1e9+7;

    int canBeSold(int mid, vector<int>&arr, int orders){
        int n = arr.size();
        for(int i=n-1; i>=0; i--){
            int balls = max(0, arr[i]-mid);
            orders -= balls;
            if(orders<0)return false;
        }

        return true;
    }

    int calcProfit(int low, vector<int> &arr, int orders){
        long long maxBalls = low;
        int ans=0;
        long long futureCost = (maxBalls*(maxBalls+1))/2;

        for(int i=0; i<arr.size(); i++){
            if(arr[i]<=maxBalls)continue;
            long long balls=arr[i];
            long long presentCost = (balls*(balls+1))/2;

            ans = (ans%mod + (int) ((presentCost - futureCost)%mod))%mod;

            orders -= (arr[i]-maxBalls);
        }

        ans = (ans%mod + (orders*maxBalls)%mod)%mod;
        return ans%mod;
    }

    int maxProfit(vector<int>& arr, int orders) 
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int l=0, h=arr.back();

        while(l<=h){
            int mid = l + (h-l)/2;
            if(canBeSold(mid, arr, orders))h=mid-1;
            else l=mid+1;
        }

        return calcProfit(l, arr, orders);
    }
};