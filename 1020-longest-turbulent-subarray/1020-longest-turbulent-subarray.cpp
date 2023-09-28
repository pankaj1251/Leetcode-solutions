class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int ans=1, cond1=1, cond2=1;
        for(int i=0; i<n-1; i++)
        {
            cond1 = arr[i]<arr[i+1] ? cond1+1:1;
            cond2 = arr[i]>arr[i+1] ? cond2+1:1;

            ans = max(ans, max(cond1, cond2));

            swap(cond1, cond2);
        }
        return ans;
    }
};