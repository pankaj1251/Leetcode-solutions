class Solution {
public:
    int func(vector<int>&arr){
        if(arr.size()==1)return arr[0]==1;

        int l=0, h=arr.size()-1;
        sort(arr.begin(), arr.end());

        while(l<=h){
            int mid = (l+h)/2;

            if(arr[mid]==1)
                h=mid-1;
            else
                l=mid+1;
        }
        return (arr.size()-1)-l+1;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();   
        vector<int>ans;
        int idx=0, size=0;
        for(int i=0; i<n; i++){
            int ones = func(arr[i]);
            if(ones>size){
                idx=i;
                size=ones;
            }
        }

        return {idx, size};
    }
};