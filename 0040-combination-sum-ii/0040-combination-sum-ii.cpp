class Solution {
public:
    void func(vector<int>& arr, int idx, int target, vector<int>&path, vector<vector<int>>&ans){

        if(target==0){
            ans.push_back(path);
            return;
        }

        for(int i=idx; i<arr.size(); i++){
            if(i>idx and arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;

            path.push_back(arr[i]);
            func(arr, i+1, target-arr[i], path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        int n = arr.size();
        vector<int>path;
        int idx=0;
        sort(arr.begin(), arr.end());
        func(arr, idx, target, path, ans);


        return ans;
    }
};