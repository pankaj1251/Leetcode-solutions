class Solution {
public:
    int func(vector<int>&arr, int L, int R){
        if(L>R)return INT_MIN;
        int mid = (L+R)/2;
        int leftSum=0, currSum=0, rightSum=0;

        for(int i=mid-1; i>=L; i--){
            currSum += arr[i];
            leftSum = max(leftSum, currSum);
        }

        currSum=0;
        for(int i=mid+1; i<=R; i++){
            currSum += arr[i];
            rightSum = max(rightSum, currSum);
        }

        return max({func(arr, L, mid-1), func(arr, mid+1, R), leftSum + arr[mid] + rightSum});
    }
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        return func(arr, 0, n-1);
    }   
};