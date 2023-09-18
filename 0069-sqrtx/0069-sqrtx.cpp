class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return x;

        int l=1, h=x;

        while(l<=h){
            int mid = l+(h-l)/2;

            if(mid==x/mid)return mid;
            else if(mid < x/mid) l=mid+1;
            else h=mid-1;
        }
        return h;
    }
};