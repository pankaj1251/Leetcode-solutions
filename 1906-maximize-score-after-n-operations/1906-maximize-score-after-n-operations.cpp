class Solution {
public:
    void func(vector<int>& arr, int i, int j, vector<int>&ans, int &res)
    {
        if(i>=arr.size() || j>arr.size()/2)
        {
            vector<int>temp = ans;
            sort(temp.begin(), temp.end());
            int temp_ans=0;
            for(int idx=0; idx<temp.size(); idx++){
                temp_ans += (idx+1)*temp[idx];
            }

            res = max(res, temp_ans);
            return;
        }

        if(arr[i]!=0)
        {
            for(int idx=i+1; idx<arr.size(); idx++)
            {
                if(arr[idx]==0)continue;

                int val = arr[idx];
                arr[idx]=0;

                ans.push_back(__gcd(arr[i], val));
                func(arr, i+1, j+1, ans, res);
                
                ans.pop_back();
                arr[idx]=val;
            }
        }
        else{
            func(arr, i+1, j, ans, res);
        }
    }
    int maxScore(vector<int>& nums) {
        vector<int>ans;
        int res=0;
        func(nums, 0, 1, ans, res);
        return res;
    }
};