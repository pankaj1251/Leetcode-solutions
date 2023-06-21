class Solution {
#define ll long long
public:
    long long findVal(vector<int>& nums, vector<int>& cost, ll mid){
        ll sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += abs(mid-nums[i])*cost[i];
        }

        return sum;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll h=0, l=1e12;
        for(int i=0; i<nums.size(); i++){
            l = min(l, (ll) nums[i]);
            h = max(h, (ll) nums[i]);
        }
        ll ans=INT_MAX;
        while(l<=h){
            ll mid = l + (h-l)/2;

            ll sum1 = findVal(nums, cost, mid);
            ll sum2 = findVal(nums, cost, mid+1);

            if(sum1<sum2){
                ans=sum1;
                h=mid-1;
            }
            else if(sum1>sum2){
                ans=sum2;
                l=mid+1;
            }
            else {ans=sum1; break;}
        }

        return ans;
    }
};