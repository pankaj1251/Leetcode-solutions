class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=1, i=0, j=0;
        int n = nums.size();
        multiset<int>mset;
        while(j<n){
            mset.insert(nums[j]);

            while(!mset.empty() && *mset.rbegin() - *mset.begin() > limit){
                mset.erase(mset.find(nums[i++]));
            }

            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};