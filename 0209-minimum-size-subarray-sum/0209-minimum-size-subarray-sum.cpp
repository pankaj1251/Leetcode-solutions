class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int count=INT_MAX;
        int sum=0;
        int l=0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            while(sum >=target){
                count = min(count, i-l+1);
                sum -= nums[l++];
            }
        }
        
        return count==INT_MAX ? 0 : count;
    }
};