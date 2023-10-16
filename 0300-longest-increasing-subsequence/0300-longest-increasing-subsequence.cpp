class Solution {
public:
    // TC: O(nlog(n))  Binary Search Approach
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp;
        int max_len=1;
        temp.push_back(arr[0]);

        for(int i=1; i<n; i++){
            if(arr[i]>temp.back()){
                temp.push_back(arr[i]);
                max_len++;
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
                temp[idx]=arr[i];
            }
        }
        return max_len;
    }
};