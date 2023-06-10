typedef long long ll;
class Solution {
public:
    bool find_ans(ll index,ll val, ll total ,ll n)
    {
        ll prev_val = val-1; //first element on left of assumed val.
                            //as value at index is "val" the value at prev and nexxt index will be "val-1" as diff<=1.
        ll next_val = n-index-1; //first element on right of assumed val.

        ll sum = val; //calculating sum of whole array.

        ll left = min(index, prev_val) , right = min(next_val, prev_val);

        sum += ((left) * (2*prev_val - left + 1))/2; //sum of AP with diff -1. as val be max in array ....3 4 "5" 4 3 2 1.
        sum += ((right) * (2*prev_val - right + 1))/2; //sum of AP with diff -1. as val be max in array ....3 4 "5" 4 3 2 1.

        if(left < index) sum += (index - left); //...1 1 1 2 3 4 5 4 3  - to find such total no of ones present on left 
        if(right < next_val) sum += (next_val - right);  //1 2 3 4 5 4 3 2 1 1 1 1...
        
        // cout << "sum = " << sum << "  val = " << val <<  endl;
        return sum <= total;
    }

    ll maxValue(ll n, ll index, ll maxSum) {
         
        ll left = 1 , right = 1e9 ,ans;

        while(left <= right) 
        {
            ll mid = (left+right)/2; //here we are assuming that mid is the largest element at given index.

            if(find_ans(index,mid,maxSum,n)){
                ans = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        return ans;
    }
};