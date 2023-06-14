class Solution {
public:
    void func(vector<int>& arr, int i, int target, vector<int>path, set<vector<int>>&ans){
        if(target<0 || i>=arr.size())return; 

        if(target==0){
            ans.insert(path);
            return;
        }

        path.push_back(arr[i]);
        func(arr, i, target-arr[i], path, ans);
        path.pop_back();
        func(arr, i+1, target, path, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        int n = arr.size();
        set<vector<int>>res;
        vector<int>path;
        func(arr, 0, target, path, res);

        for(auto &it: res)ans.push_back(it);

        return ans;
    }
};