class Solution {
public:
    vector<int>X = {0,1,0,-1};
    vector<int>Y = {1,0,-1,0};

    bool check(vector<vector<char>>& arr, string word, string str, int i, int j, int idx)
    {
        if(idx == word.size())return true;

        if(i>=arr.size() || i<0 || j>=arr[0].size() || j<0 || arr[i][j]!=word[idx])return false;

        arr[i][j] = '0';

        bool flag = check(arr, word, str+arr[i][j], i+1, j, idx+1) || 
                    check(arr, word, str+arr[i][j], i-1, j, idx+1) ||
                    check(arr, word, str+arr[i][j], i, j+1, idx+1) || 
                    check(arr, word, str+arr[i][j], i, j-1, idx+1);

        arr[i][j] = word[idx];

        return flag;
    }
    bool exist(vector<vector<char>>& arr, string word) {
        int n = arr.size();
        int m = arr[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == word[0]){
                    if(check(arr, word, "", i, j, 0)==true)return true;
                }
            }
        }

        return false;
    }
};