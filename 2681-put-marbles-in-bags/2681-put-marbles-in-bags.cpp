class Solution {
public:
    long long putMarbles(vector<int>& arr, int k) {
        int n = arr.size();
        long long minm = arr[0]+arr[n-1];
        long long maxm = arr[0]+arr[n-1];

        vector<long long>sum;

        for(int i=0; i<n-1; i++){
            sum.push_back(arr[i]+arr[i+1]);
        }

        sort(sum.begin(), sum.end());

        for(int i=0; i<k-1; i++){ //k-1 bcz to partition into k parts we need k-1 lines to partition.
            maxm += (long long) sum[sum.size()-i-1];
            minm += (long long) sum[i];
        }

        return (maxm-minm);
    }
};