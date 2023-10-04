class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0, h=0, n=nums.size();
        for(int i=0; i<n; i++){
            l=max(l, nums[i]);
            h += nums[i];
        }   

        int ans=0;
        while(l<=h){
            int mid = (l+h)/2;
            int count=0, tempsum=0;
            for(int i=0; i<n; i++){
                if(tempsum+nums[i]<=mid){
                    tempsum += nums[i];
                }
                else count++, tempsum=nums[i];
            }
            count++;


            if(count<=k)h=mid-1, ans=mid;
            else l=mid+1;
        }

        return ans;
    }
};