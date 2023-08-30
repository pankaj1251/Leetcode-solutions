class Solution {
public:
        
    int mod = 1e9 + 7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
                
        int n = arr.size();
        long long  Kadnes_ans = 0;
        long long array_sum = 0;
        
        // Using Kadnes Algo 
            long long temp = 0;
        for(int i =0;i < n ;i++){
                temp += arr[i];
                if(temp < 0) temp =0;
                Kadnes_ans = max(Kadnes_ans,temp);
        }

        if(k == 1) return Kadnes_ans%mod;
        
    
        long long bestpreffix = 0;
        long long bestsuffix = 0;
        temp = 0;

        for(int i = 0 ; i < n ; i++){
            temp += arr[i];
            bestpreffix= max(bestpreffix , temp);
            
        }
        
        array_sum = temp;  
        temp = 0;
        for(int i = n-1 ; i>= 0;i--){
                temp += arr[i];
                bestsuffix = max(bestsuffix,temp);
                                    
        }

        long long ans;  
        if(array_sum >= 0) ans = max(bestpreffix + bestsuffix +  (long long)(k-2)*(long long)(array_sum)  ,Kadnes_ans );

        else ans =  max((bestpreffix + bestsuffix), Kadnes_ans);
                    
        return ans%mod;    
    }
};