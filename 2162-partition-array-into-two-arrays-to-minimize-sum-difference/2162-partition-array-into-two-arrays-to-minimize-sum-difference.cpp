class Solution {
public:
    //Power set
    vector<vector<int>>allsubsetsum(vector<int>&arr, int l, int r)
    {
        int n = r-l+1;
        vector<vector<int>>ans(n+1);

        for(int i=0; i<(1<<n); i++){
            int sum=0, sz=0;
            for(int j=0; j<n; j++){
                if(i & (1<<j)){
                    sum += arr[l+j];
                    sz++;
                }
            }
            ans[sz].push_back(sum);
        }

        return ans;
    }

    int minimumDifference(vector<int>& arr) {
        int n = arr.size();    
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        auto left = allsubsetsum(arr, 0, n/2-1);
        auto right = allsubsetsum(arr, n/2, n-1);

        int target = totalSum/2, ans=INT_MAX;

        //we can take (0 to n/2) length numbers from left
        for(int i=0; i<=n/2; i++){
            //now we take rest - (n/2-i) length from right, we sort it to binary search
            vector<int>right_array = right[n/2-i];
            sort(right_array.begin(), right_array.end());

            for(int curleftSum : left[i]){
                int neededSumfromRight = target - curleftSum;
                auto it = lower_bound(right_array.begin(), right_array.end(), neededSumfromRight);
                if(it != right_array.end()){
                    ans = min(ans, abs(totalSum - 2*(curleftSum + *it)));
                }
            }

        }
        return ans;
    }
};