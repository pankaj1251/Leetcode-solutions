class Solution {
public:
    long long minimumReplacement(vector<int>& arr) {
        int n = arr.size();
        long long ans=0;
        long long last=arr[n-1];

        for(int i=n-2; i>=0; i--){
            if(arr[i]>last){
                int temp = arr[i]/last;
                if(arr[i] % last)temp++;
                last=arr[i]/temp;
                ans += temp-1;
            }
            else last=arr[i];
        }
        return ans;
    }
};