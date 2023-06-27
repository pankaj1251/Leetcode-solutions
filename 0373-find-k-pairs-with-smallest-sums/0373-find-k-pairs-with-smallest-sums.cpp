class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& arr1, vector<int>& arr2, int k) {
        int n1 = arr1.size(), n2 = arr2.size();
        vector<vector<int>>ans;
        priority_queue<pair<int, pair<int, int>>>pq;

        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                int sum = arr1[i]+arr2[j];

                if(pq.size()<k)pq.push({sum, {arr1[i], arr2[j]}});
                else if(sum < pq.top().first){
                    pq.pop();
                    pq.push({sum, {arr1[i], arr2[j]}});
                }
                else break;
            }
        }

        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};