class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n = nums.size();
        int i=0, j=0;

        while(i<n){
            
            while(j<n-1 and nums[j+1]==1+nums[j])j++;

            string str = "";
            if(i==j) str = to_string(nums[i]);
            else str = to_string(nums[i]) + "->" + to_string(nums[j]);

            ans.push_back(str);
            i=j+1;
            j++;
            // i++;
        }

        return ans;
    }
};