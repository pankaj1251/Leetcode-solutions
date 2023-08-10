class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int l=0, h=n-1;

        while(l<=h){
            int mid = (l+h)/2;

            if(arr[mid]==target)return true;

            if(arr[l]==arr[mid] && arr[mid]==arr[h]){ //for duplicates only
                h--;
                l++;
            }
            else if(arr[l]<=arr[mid]){
                if(target>=arr[l] and arr[mid]>=target)h=mid-1;
                else l=mid+1;
            }
            else{
                if(target>=arr[mid] and arr[h]>=target)l=mid+1;
                else h=mid-1;
            }
        }

        return false;
    }
};