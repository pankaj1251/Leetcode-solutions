class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        set<vector<int>>st;
        vector<vector<int>>ans;

        if(n<4)return ans;
        
        int k, l;
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                k=j+1, l = n-1;

                while(k<l){
                    long long sum = arr[i];
                    sum+=arr[j];
                    sum+=arr[k];
                    sum+=arr[l];
                    
                    if(sum ==target){
                        st.insert({arr[i], arr[j], arr[k], arr[l]});
                        k++;l--;
                    }
                    else if(sum<target)k++;
                    else l--;
                }
            }
        }

        for(auto &it: st){
            ans.push_back(it);
        }

        return ans;
    }
};