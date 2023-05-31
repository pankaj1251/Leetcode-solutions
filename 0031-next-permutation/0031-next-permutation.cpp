class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return;
        int i=n-1;
        while(i>0){
            if(arr[i]>arr[i-1])break;
            i--;
        }

        if(i==0){
            sort(arr.begin(), arr.end());
            return;
        }

        int idx = -1, j=i;
        int temp = arr[i-1];

        while(j<n){
            if(arr[j]<=temp)break;
            j++;
        }

        swap(arr[i-1], arr[j-1]); // here we want to swap the next greater element than temp.

        sort(arr.begin()+i, arr.end());
    }
};