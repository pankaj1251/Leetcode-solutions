class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int k) {
        int n = values.size();
        unordered_map<int, int>mp;
        int ans = 0;
        vector<pair<int, int>>vp;
        for(int i=0; i<n; i++){
            vp.push_back({values[i], labels[i]});
        }

        sort(vp.rbegin(), vp.rend());

        for(int i=0; i<n; i++){
            if(mp[vp[i].second]<k){
                ans += vp[i].first;
                mp[vp[i].second]++;
                numWanted--;
                if(numWanted==0)break;  
            }
        }
        return ans;
    }
};