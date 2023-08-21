class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        sort(nums.begin(), nums.end());
        int i=0, j = n-1;
        while(i<j){
            arr.push_back(nums[i]);
            arr.push_back(nums[j]);
            i++;j--;
        }
        cout<<i<<" "<<j<<endl;
        if(i<=j)arr.push_back(nums[i++]);
        return arr;
    }
};