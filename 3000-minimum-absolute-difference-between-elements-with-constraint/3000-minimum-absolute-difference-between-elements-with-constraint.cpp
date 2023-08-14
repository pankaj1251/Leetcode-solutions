class Solution {
public:
    int minAbsoluteDifference(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = INT_MAX;
        set<int>vis;

        int i=0, j=k;
        while(j<n){
            vis.insert(arr[i]);
            auto idx = vis.lower_bound(arr[j]);

            //to check if idx is present in set or not.
            if(idx != vis.end()) ans = min(ans, abs(*idx - arr[j]));

            // Check if the iterator idx has not reached the beginning of the set s
            // Move the iterator idx one step back (to the smaller element) using idx--,
            // then update ans again by comparing
            if(idx != vis.begin()) idx--, ans = min(ans, abs(*idx - arr[j]));
            j++;
            i++;
        }

        return ans;
    }
};