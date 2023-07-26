class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i=0, j = n-1;

        while(i<=j){
            int mid = i + (j-i)/2;

            if(mid>0 and mid<n-1 and arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1])return mid;
            else if(mid>0 and arr[mid]>arr[mid-1])i++;
            else j--;
        }

        return -1;
    }
};