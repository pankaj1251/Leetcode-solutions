class Solution {
public:
    int findMinMoves(vector<int>& arr) {
        int n = arr.size();
        int sum=0;
        for(int i=0; i<n; i++)sum += arr[i];
        int val;
        if(sum%n != 0)return -1;
        else val = sum/n;
        int ans=0, extra=0;
        for(int i=0; i<n; i++){
            extra += arr[i]-val;
            ans = max({ans, arr[i]-val, abs(extra)});
        }

        return ans;
    }
};