class Solution {
public:
    void func(int n, set<int>&st)
    {
        for(int i=2; i*i<=n; i++){
            while(n%i==0){
                st.insert(i);
                n/=i;
            }
        }
        if(n>1)st.insert(n);
    }
    int distinctPrimeFactors(vector<int>& arr) {
        
        int n = arr.size();
        set<int>st;
        for(int i=0; i<n; i++){
            func(arr[i], st);
        }
        
        return st.size();
    }
};