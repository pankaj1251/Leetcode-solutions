class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>back(n), front(n);
        int maxm = height[0];
        for(int i=0; i<n; i++){
            maxm = max(maxm, height[i]);
            front[i] = maxm;
        }

        maxm = height[n-1];

        for(int i=n-1; i>=0; i--){
            maxm = max(maxm, height[i]);
            back[i]= maxm;
        }

        int ans=0;

        for(int i=0; i<n; i++){
            ans += min(front[i], back[i]) - height[i]; 
        }

        return ans;
    }
};