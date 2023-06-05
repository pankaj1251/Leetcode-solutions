class Solution {
public:
    int mod = 1e9+7;
    int numSubseq(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int>no_of_subseq(n+1, 1);

        for(int i=1; i<n; i++){
            no_of_subseq[i] = (2 * no_of_subseq[i-1])%mod;
        }

        int i=0, j=n-1;
        int ans=0;
        while(i<=j){
            if(arr[i]+arr[j]<=target){
                ans = (ans + no_of_subseq[j-i])%mod;
                i++;
            }
            else j--;
        }

        return ans;
    }
};