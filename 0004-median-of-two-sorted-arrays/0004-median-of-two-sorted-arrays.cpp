class Solution {
public:
    double func(vector<int>& arr1, vector<int>& arr2){
        int n1 = arr1.size(), n2=arr2.size();
        int n = n1+n2;
        if(n1>n2)return func(arr2, arr1);

        int l=0, h=n1;
        int left = (n1+n2+1)/2;


        while(l<=h){
            int mid1 = (l+h)/2;
            int mid2 = left-mid1;

            int l1 = INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;

            if(mid1<n1)r1=arr1[mid1];
            if(mid2<n2)r2=arr2[mid2];
            if(mid1-1>=0)l1=arr1[mid1-1];
            if(mid2-1>=0)l2=arr2[mid2-1];

            if(l1<=r2 and l2<=r1){ //check this condition carefully.
                if(n%2!=0) return max(l1, l2);
                return ((double) (max(l1, l2)+min(r1, r2)))/2.0;
            }
            else if(l1>r2)h=mid1-1;
            else l=mid1+1;
        }

        return 0;
    }
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2=arr2.size();
        return func(arr1, arr2);
    }
};