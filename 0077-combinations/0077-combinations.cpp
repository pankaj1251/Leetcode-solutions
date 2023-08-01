class Solution {
public:
    void func(int i, int n, int k, vector<int>v, vector<vector<int>> &ans){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }

        for(int idx=i; idx<=n; idx++){
            v.push_back(idx);
            func(idx+1, n, k, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        func(1, n, k, v, ans);
        return ans;
    }
};