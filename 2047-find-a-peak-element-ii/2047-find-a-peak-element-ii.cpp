class Solution {
public:
    int func(vector<vector<int>>&arr, int n, int m, int mid){
        int maxm=-1;
        int idx=-1;
        for(int j=0; j<n; j++){
            if(arr[j][mid]>maxm){
                maxm=arr[j][mid];
                idx=j;
            }
        }

        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int n = arr.size(), m=arr[0].size();

        int l=0, h=m-1;
        while(l<=h){
            int mid = (l+h)/2;
            int max_idx = func(arr, n, m, mid);
            int left = mid-1>=0 ? arr[max_idx][mid-1] : -1;
            int right = mid+1<m ? arr[max_idx][mid+1] : -1;

            if(arr[max_idx][mid]>left and arr[max_idx][mid]>right)return {max_idx, mid};
            else if(arr[max_idx][mid]<left){
                h=mid-1;
            }
            else l=mid+1;
        }

        return {-1, -1};
    }
};