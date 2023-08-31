class Solution {
public:
    int maximumTop(vector<int>& arr, int k) {
        int n = arr.size();

        if(k==0) return n>=1 ? arr[0]:-1;
        if(k==1) return n==1 ? -1 : arr[1]; //remove first element.
        if(n==1) return k%2==0 ? arr[0]: -1; //as we are adding and removing so two * moves to valid answer.

        int maxm=INT_MIN;
        for(int i=0; i<min(k-1, n); i++)maxm = max(maxm, arr[i]);
        if(k<n)maxm = max(maxm, arr[k]);
        return maxm;
    }
};