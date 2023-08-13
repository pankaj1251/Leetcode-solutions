class Solution {
public:
    int bfs(vector<vector<int>>& arr, int i, int j){
        if(i<0 || i>=arr.size() || j<0 || j>=arr[0].size() || arr[i][j]==0)return 0;

        arr[i][j]=0;

        return 1 + bfs(arr, i+1, j) + bfs(arr, i-1, j) + bfs(arr, i, j-1) + bfs(arr, i, j+1);

    }
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();

        vector<pair<int, int>>vp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1){
                    vp.push_back({i, j});
                }
            }
        }

        int ans = 0;
        for(int i=0; i<vp.size(); i++){
            ans = max(ans, bfs(arr, vp[i].first, vp[i].second));
        }

        return ans;
    }
};