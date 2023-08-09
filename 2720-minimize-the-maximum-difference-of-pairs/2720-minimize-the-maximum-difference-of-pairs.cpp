class Solution {
public:
    bool func(vector<int>&arr, int p, int diff){
        int n = arr.size();
        int c=0;
        for(int i=0; i<n-1; i++){
            if(arr[i+1]-arr[i] <= diff){
                c++;
                i++;
            }
            if(c>=p)return true;
        }

        return false;
    }

    int minimizeMax(vector<int>& arr, int p) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int l=0, h=arr[n-1]-arr[0];
        
        while(l<h){
            int mid = (l+h)/2;

            if(func(arr, p, mid))h=mid;
            else l = mid+1;
        }

        return l;
    }
};