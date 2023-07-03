class Solution {
public:
    void func(int idx, int n, int k, string num, vector<int>&ans){
        if(idx==n){
            int temp = stoi(num);
            ans.push_back(temp);
            return;
        }

        int ch = num[idx-1]-'0';
       
        for(int i=0; i<=9; i++){
            if(abs(ch-i)==k)
            {
                num.push_back(i+'0');
                func(idx+1, n, k, num, ans);
                num.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string num="";
        vector<int>ans;

        for(int i=1; i<=9; i++){
            num.push_back(i+'0');
            func(1, n, k, num, ans);
            num.pop_back();
        }

        return ans;
    }
};