class Solution {
public:
    vector<pair<int, int>>dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void buildDist(queue<pair<int, int>> &Q, int n, vector<vector<int>> &dist, vector<vector<bool>> &vis){
        int lvl=0;

        while(!Q.empty()){
            int sz = Q.size();
            while(sz--){
                auto [x, y] = Q.front();Q.pop();
                dist[x][y]=lvl;
                for(int i=0; i<4; i++){
                    int nx = x + dir[i].first, ny = y + dir[i].second;
                    if(nx>=0 and nx<n and ny>=0 and ny<n and !vis[nx][ny]){
                        vis[nx][ny]=true;
                        Q.push({nx, ny});
                    }
                }
            }
            lvl++;
        }
    }

    int func(vector<vector<int>> &dist, int n){
        priority_queue<pair<int, pair<int, int>>>PQ; //we are using PQ as it is maxheap, so it will always have max distance on top,will remain until we reach [n-1][n-1].
        vector<vector<bool>>vis(n, vector<bool>(n));

        PQ.push({dist[0][0], {0, 0}});
        vis[0][0]=true;
        int ans = INT_MAX;

        while(!PQ.empty()){
            auto [D, idx] = PQ.top();
            PQ.pop();

            int x = idx.first, y = idx.second;
            ans = min(ans, dist[x][y]);

            if(x==n-1 and y==n-1)return ans;

            for(int i=0; i<4; i++){
                int nx = x+dir[i].first, ny = y+dir[i].second;
                if(nx>=0 && nx<n && ny>=0 && ny<n &&!vis[nx][ny]){
                    vis[nx][ny] = true;
                    PQ.push({dist[nx][ny],{nx,ny}});
                }
            }
        }

        return ans;
    }
    int maximumSafenessFactor(vector<vector<int>>& arr) {
        int n = arr.size();
        queue<pair<int, int>>Q;
        vector<vector<bool>>vis(n, vector<bool>(n));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]==1){vis[i][j] = true; Q.push({i, j});}
            }
        }

        vector<vector<int>>dist(n, vector<int>(n));
        
        buildDist(Q, n, dist, vis);

        return func(dist, n);
    }
};