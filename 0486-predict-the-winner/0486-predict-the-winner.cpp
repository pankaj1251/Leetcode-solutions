class Solution {
public:

    int func(vector<int>& arr, bool flag, int i, int j, int n)
    {
        if(i>=arr.size() || j<0 || i>j)return 0;
        
        if(flag) return max(arr[i] + func(arr, !flag, i+1, j, n), arr[j] + func(arr, !flag, i, j-1, n));
        
        else return min(-arr[i] + func(arr, !flag, i+1, j, n), -arr[j] + func(arr, !flag, i, j-1, n));
    }
    bool PredictTheWinner(vector<int>& arr) {

        int n = arr.size();
        int ans = func(arr, true, 0, n-1, n);
        
        return ans>=0;
    }
};