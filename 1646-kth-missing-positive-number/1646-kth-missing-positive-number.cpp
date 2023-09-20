class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n =arr.size();
        int l=0, h=n-1;
        while(l<=h)
        {
            int mid = (h+l)/2;
            int diff = arr[mid]-mid;

            if(diff-1 < k){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }

        return l+k;
    }
};