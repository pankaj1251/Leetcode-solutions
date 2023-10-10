class Solution {
public:
    int func(vector<vector<int>>&arr, int i, int j){
        if(i>=arr.size() || j>=arr[0].size() || arr[i][j]==0)return 0;

        if(i==arr.size()-1 and j==arr[0].size()-1)return 1;

        arr[i][j]=0;
        return func(arr, i+1, j) || func(arr, i, j+1);
    }
    bool isPossibleToCutPath(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        // vector<vector<int>>dp(n, vector<int>(m, -1));
        if(func(arr, 0, 0)==false)return true;
        arr[0][0]=arr[n-1][m-1]=1;

        return !func(arr, 0, 0);
    }
};