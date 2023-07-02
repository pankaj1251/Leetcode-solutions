class Solution {
public:

    void func(vector<vector<int>>& arr, int idx, vector<int> &indegree, int &ans, int count){
        if(idx==arr.size()){
            for(auto it: indegree){
                if(it != 0)return;
            }
            ans = max(ans, count);
            return;
        }

        //take
        indegree[arr[idx][0]]--;
        indegree[arr[idx][1]]++;
        func(arr, idx+1, indegree, ans, count+1);

        //not take
        indegree[arr[idx][0]]++;
        indegree[arr[idx][1]]--;
        func(arr, idx+1, indegree, ans, count);
    }

    int maximumRequests(int n, vector<vector<int>>& arr) {
        vector<int>indegree(n, 0);
        int ans=0;

        func(arr, 0, indegree, ans, 0);

        return ans;
    }
};