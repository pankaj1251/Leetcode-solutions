class Solution {
public:
    int maximumScore(vector<int>& arr, int k) {
        int n = arr.size();
        int left=k, right=k;

        int min_val = arr[k];
        int ans = min_val;

        while(left>0 || right < n-1){
            if(left==0 || (right<n-1 and arr[right+1] > arr[left-1])){  // select maximum min element to cght max result.
                right++;
            }
            else left--;

            min_val = min(min_val, min(arr[left], arr[right]));
            ans = max(ans, min_val * (right-left+1));
        }

        return ans;
    }
};