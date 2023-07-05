class Solution {
public:
    void func(vector<int>& arr, int idx, vector<int> &groups, int &ans, int k){
        if(idx >=arr.size()){
            int temp = groups.size();
            ans = min(ans, temp);
            return;
        }

        if(groups.size()>ans)return;

        for(int i=0; i<groups.size(); i++)
        {
            if(groups[i]+arr[idx] <= k){
                groups[i] += arr[idx];
                func(arr, idx+1, groups, ans, k);
                groups[i] -= arr[idx];
            }
        }

        groups.push_back(arr[idx]);
        func(arr, idx+1, groups, ans, k);
        groups.pop_back();
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        int ans=INT_MAX;
        vector<int>groups;
        func(tasks, 0, groups, ans, sessionTime);
        return ans;
    }
};