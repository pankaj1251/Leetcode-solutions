class Solution {
public:
    vector<int>x_dir = {-1, 0, 1, 0};
    vector<int>y_dir = {0, 1, 0, -1};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>PQ;
   
    int minimumEffortPath(vector<vector<int>>& arr) {
        PQ.push({0, {0,0}});
        int ans=0;
        int n = arr.size(), m=arr[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        while(!PQ.empty()){
            auto top = PQ.top();
            PQ.pop();

            int dist = top.first;
            int x = top.second.first;
            int y = top.second.second;

            ans = max(ans, dist);
            vis[x][y]=1;

            if(x==n-1 and y==m-1)break;
            
            for(int i=0; i<4; i++)
            {
                int nx = x + x_dir[i];
                int ny = y + y_dir[i];

                if(nx>=0 and ny>=0 and nx<n and ny<m and !vis[nx][ny])
                    PQ.push({abs(arr[x][y]-arr[nx][ny]), {nx, ny}});
            }
        }
        return ans;
    }

};