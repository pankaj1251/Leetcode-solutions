class Solution {
public:
    void func(vector<int>& arr, int idx, int target, vector<int>path, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(path);
            return;
        }

        if(target<0 || idx>=arr.size())return; 

        for(int i=idx; i<arr.size(); i++){
            if(i>idx and arr[i-1]==arr[i])continue;

            path.push_back(arr[i]);
            func(arr, i+1, target-arr[i], path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) 
    {
        int n = arr.size();
        vector<int>path;
        vector<vector<int>>ans;

        sort(arr.begin(), arr.end());

        func(arr, 0, target, path, ans);

        return ans;
    }
};