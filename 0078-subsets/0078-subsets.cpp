class Solution {
public:
    void func(vector<int>& arr, int idx, set<vector<int>>&ans, vector<int>subset)
    {
        if(idx==arr.size()){
            ans.insert(subset);
            return;
        }

        subset.push_back(arr[idx]);

        func(arr, idx+1, ans, subset);

        subset.pop_back();

        func(arr, idx+1, ans, subset);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>>ans;
        set<vector<int>>subsets;
        vector<int>st;
        func(arr, 0, subsets, st);

        for(auto it: subsets){
            ans.push_back(it);
        }

        return ans;
    }
};