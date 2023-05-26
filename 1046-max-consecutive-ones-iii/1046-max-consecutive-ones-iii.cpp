class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int i=0, j=0;
        int c=0, ans=0, n = arr.size();
        
        while(j<n){
            if(arr[j]==0){c++;j++;}
            else j++;

            if(c==k){
                ans = max(ans, j-i);
            }
            if(c>k){
                while(arr[i]!=0){
                    i++;
                }
                i++;
                c--;
            }
        }

        return c<k?n:ans;
    }
};