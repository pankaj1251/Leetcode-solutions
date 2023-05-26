class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        long sum=0;
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        
        if(k==n)return sum;

        int i=0, j=0;
        long temp=0, ans=sum+1;
        while(j<n-k){
            temp += arr[j];
            j++;
        }

        ans = min(ans, temp);

        while(j<n){
            temp += arr[j];
            temp -= arr[i];
            j++;
            i++;
            ans = min(ans, temp);
        }

        return sum - ans;
    }
};