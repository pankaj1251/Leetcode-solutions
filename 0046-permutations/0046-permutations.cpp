class Solution {
public:
    void func(vector<int>& arr, int n, vector<int>&perm, vector<int>&freq, vector<vector<int>>&ans){
        if(perm.size()==n){
            ans.push_back(perm);
            return;
        }

        for(int i=0; i<n; i++){
            if(freq[i]==0){
                freq[i]=1;
                perm.push_back(arr[i]);
                func(arr, n, perm, freq, ans);
                perm.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>>ans;
        int n = arr.size();
        vector<int>perm, freq(n, 0);
        func(arr, n, perm, freq, ans);

        return ans;
    }
};