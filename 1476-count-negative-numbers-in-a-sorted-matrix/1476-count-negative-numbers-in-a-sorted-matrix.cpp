class Solution {
public:
int binaryS(vector<int>arr, int i, int j){
    while(i<j){
        int mid = (i+j)/2;
        if(arr[mid]>=0){
            return binaryS(arr, mid+1, j);
        }
        else return binaryS(arr, i, mid);
    }
    return arr.size()-i;
}
    int countNegatives(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            if(arr[i][m-1]<0){
                ans += binaryS(arr[i], 0, m);
            }
        }

        return ans;
    }
};