class Solution {
public:

    int func(int n){
        long long sum=0;
        for(int i=2; i*i<=n; i++){
            while(n%i==0){
                sum += i;
                n/=i;
            }
        }

        if(n>1)return n+sum;
        return sum;
    }

    int smallestValue(int n) {
        while(true){
            int temp = func(n);
            if(n==temp)return n;
            n=func(n);
        }

        return n;
    }
};