class Solution {
public:
    int n, m;
    bool isZero(vector<vector<int>>&arr){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j])return false;
            }
        }
        return true;
    }

    vector<vector<int>> &flipMat(vector<vector<int>> &arr, int i, int j){
        arr[i][j] ^= 1;

        if(i-1>=0)arr[i-1][j] ^= 1;
        if(i+1<n)arr[i+1][j] ^= 1;
        if(j-1>=0)arr[i][j-1] ^= 1;
        if(j+1<m)arr[i][j+1] ^= 1;

        return arr;
    }

    int func(vector<vector<int>> arr, int i, int j) //we are not passing arr by reference here as we need arr in their previous state also for recursive calls, so we are creating new copy ecerytime here.
    {
        if(j==m) i++, j=0;
        if(i==n) return isZero(arr) ? 0 : 10000;

        int no_flip = func(arr, i, j+1);
 
        int flip = func(flipMat(arr, i, j), i, j+1) + 1;

        return min(flip, no_flip);
    }
    int minFlips(vector<vector<int>>& arr) {
        n = arr.size(), m = arr[0].size();
        int ans = func(arr, 0, 0);
        return (ans>=1000 ? -1 : ans);
    }
};