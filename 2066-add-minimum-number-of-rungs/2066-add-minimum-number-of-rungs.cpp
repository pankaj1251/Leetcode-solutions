class Solution {
public:
    int addRungs(vector<int>& arr, int dist) {
        int n = arr.size();
        int ans=0;

        if(arr[0]>dist){
            int temp = (arr[0]-1)/dist;
            ans += temp;
        }

        int i=0;

        while(i<n-1){
            if(arr[i+1]-arr[i]>dist){
                int temp = (arr[i+1]-arr[i]-1)/dist;
                ans += temp;
            }
            i++;
        }

        return ans;
    }
};