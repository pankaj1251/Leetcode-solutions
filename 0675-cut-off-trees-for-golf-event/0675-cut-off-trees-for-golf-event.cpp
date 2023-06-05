class Solution {
public:
    vector<int>dir_x = {0,-1,0,1};
    vector<int>dir_y = {1,0,-1,0};

    int bfs(vector<vector<int>>& forest, int start_x, int start_y, int next_x, int next_y)
    {
        int n = forest.size(), m = forest[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        queue<pair<int, int>>Q;
        Q.push({start_x, start_y});
        vis[start_x][start_y]=true;
        int ans=0;
        while(!Q.empty()){
            int sz = Q.size();
            while(sz--){
                auto it = Q.front();
                Q.pop();

                if(it.first==next_x and it.second==next_y)return ans;

                for(int i=0; i<4; i++){
                    int nx = it.first + dir_x[i];
                    int ny = it.second + dir_y[i];

                    if(nx<0 || ny<0 || nx==n || ny==m || forest[nx][ny]==0 || vis[nx][ny]==true){
                        continue;
                    }
                    Q.push({nx, ny});
                    vis[nx][ny]=true;
                }
            }
            ans++;
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size(), m = forest[0].size();
        vector<vector<int>>trees;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(forest[i][j]>1){
                    trees.push_back({forest[i][j], i, j});
                }
            }
        }

        sort(trees.begin(), trees.end());

        int start_x=0, start_y=0;
        int ans=0;
        
        for(auto tree: trees)
        {
            int next_x = tree[1];
            int next_y = tree[2];
            
            int distance = bfs(forest, start_x, start_y, next_x, next_y);
            
            if(distance == -1)return -1;

            ans += distance;
            start_x=next_x;
            start_y=next_y;
        }
        return ans;
    }
};