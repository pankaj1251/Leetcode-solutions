class Solution {
public:
    bool check(vector<int>arr){
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i] % (i+1) != 0 and (i+1) % arr[i] != 0)return false;
        }
        return true;
    }
    void func(vector<int>&arr, int idx, int &ans){
        if(idx==arr.size()){
            ans++;
            return;
        }

        for(int i=idx; i<arr.size(); i++){
            if(arr[i] % (idx+1) == 0 || (idx+1) % arr[i] == 0){
                swap(arr[i], arr[idx]);
                func(arr, idx+1, ans);
                swap(arr[i], arr[idx]);
            }
        }
    }
    int countArrangement(int n) {
        vector<int>arr(n);
        for(int i=0; i<n; i++)arr[i]=i+1;
        int ans=0;
        func(arr, 0, ans);
        return ans;
    }
};