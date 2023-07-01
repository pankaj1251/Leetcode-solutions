class Solution {
public:
    void func(int idx, vector<int>& cookies, int k, vector<int>& distr, int &ans){
        if(idx==cookies.size()){
            int temp = INT_MIN;
            for(auto it: distr){
                temp = max(temp, it);
            }
            ans = min(ans, temp);
            return;
        }

        for(int i=0; i<k; i++){
            distr[i] += cookies[idx];
            func(idx+1, cookies, k, distr, ans);
            distr[i] -= cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int>distribution(k, 0);
        func(0, cookies, k, distribution, ans);

        return ans;
    }
};