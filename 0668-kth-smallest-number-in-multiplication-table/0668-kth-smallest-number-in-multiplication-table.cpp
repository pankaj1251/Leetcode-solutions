class Solution {
public:
    bool kSmaller(int n, int m, int mid, int k) {
        int c = 0;
        for (int i = 1; i <= n; i++)
            c += min(m, mid/i);
        
        return c >= k;
    }
    
    int findKthNumber(int n, int m, int k) {
        int lo = 0, hi = m*n, mid, res;
        
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            if (kSmaller(n, m, mid, k)) hi = mid-1;
            else lo = mid + 1;
        }
        
        return lo;
    }
};