class Solution {
public:
    int func(vector<string>&arr, int idx, char first, char last, vector<vector<vector<int>>> &dp)
    {
        if(idx==arr.size())return 0;
        if(dp[idx][first-'a'][last-'a'] != -1)return dp[idx][first-'a'][last-'a'];
        
        int a1=0, a2=0;
        string temp=arr[idx];

        if(last==temp[0]){
            a1 = 1 + func(arr, idx+1, first, temp[temp.size()-1], dp);
        }
        else{
            a1 = func(arr, idx+1, first, temp[temp.size()-1], dp);
        }
        
        if(first == temp[temp.size()-1]){
            a2 = 1 + func(arr, idx+1, temp[0], last, dp);
        }
        else{
            a2 = func(arr, idx+1, temp[0], last, dp);
        }
       
        return dp[idx][first-'a'][last-'a'] = max(a1, a2);
        
    }
    int minimizeConcatenatedLength(vector<string>& arr) {
        int n = arr.size();
        int sz=0;
        for(auto &it: arr)sz+=it.size();

        vector<vector<vector<int>>>dp(sz+1, vector<vector<int>>(26, vector<int>(26, -1)));
        string str=arr[0];
        return sz - func(arr, 1, str[0], str[str.length()-1], dp);
    }
};