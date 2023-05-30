class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0; i<n; i++){
            int j=i+1, k = n-1;

            while(j<k)
            {
                if(arr[i] + arr[j] + arr[k] > 0)k--;

                else if(arr[i] + arr[j] + arr[k] < 0)j++;
                
                else {
                    st.insert({arr[i], arr[j], arr[k]});
                    j++;
                    k--;
                }
            }
        }

        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};