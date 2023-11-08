class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int minStep = std::max(std::abs(sx - fx), std::abs(sy - fy));
        
        if (minStep == 0) {
            return t != 1;
        }
        
        return minStep <= t;
    }
};
