class Solution {
public:
    void func(vector<int>& arr, int i, int target, int prev, vector<int>path, set<vector<int>>&ans){
        if(target==0){
            ans.insert(path);
            return;
        }

        if(target<0 || i>=arr.size())return; 

        func(arr, i+1, target, target, path, ans);
        if(i>0 and arr[i-1]==arr[i] and prev==target)return;
        path.push_back(arr[i]);
        func(arr, i+1, target-arr[i], target, path, ans);
        path.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        int n = arr.size();
        set<vector<int>>res;
        vector<int>path;
        sort(arr.begin(), arr.end());
        func(arr, 0, target, target, path, res);

        for(auto &it: res)ans.push_back(it);

        return ans;
    }
};