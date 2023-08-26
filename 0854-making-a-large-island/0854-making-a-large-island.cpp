class Solution {
public:
    int area=0, idx=2; //as 0 and 1 are already inthe matrix.
    vector<pair<int, int>>directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    unordered_map<int, int>mp;

    void dfs(int i, int j, vector<vector<int>> &arr){
        if(i<0 || j<0 || i>=arr.size() || j>=arr.size() ||arr[i][j] != 1)return;

        mp[idx]++;
        arr[i][j]=idx;
        for(auto dir: directions){
            dfs(i+dir.first, j+dir.second, arr);
        }
    }

    void markAllConnectedComponents(vector<vector<int>> &arr){
        int n = arr.size();
        idx=2;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]==1){
                    dfs(i, j, arr);
                    area = max(area, mp[idx]);
                    idx++;
                }
            }
        }
    }

    void findMaxArea(vector<vector<int>> &arr){
        int n = arr.size();
        queue<pair<int, int>>Q;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]==0)Q.push({i, j});
            }
        }

        while(!Q.empty()){
            auto node=Q.front();
            Q.pop();
            int x = node.first;
            int y = node.second;

            unordered_set<int>vis;
            int curr=0;
            for(auto dir: directions){
                int nx = dir.first + x;
                int ny = dir.second + y;

                if((nx>=0 and ny>=0 and nx<arr.size() and ny<arr.size() and arr[nx][ny] != 0) and !vis.count(arr[nx][ny])){
                    vis.insert(arr[nx][ny]);
                    curr += mp[arr[nx][ny]];
                }
            }

            area = max(area, curr+1); //+1 because we need to consider the flipped 0 also.
        }
    }

    int largestIsland(vector<vector<int>>& arr) {
        int n = arr.size();

        markAllConnectedComponents(arr);

        findMaxArea(arr);

        return area;
    }
};