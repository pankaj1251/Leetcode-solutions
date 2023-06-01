class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& arr) {
        int n = arr.size();
        if(arr[0][0] != 0 || arr[n-1][n-1]!=0)return -1;
        
        queue<pair<int, int>>Q;
        vector<vector<int>>distance(n, vector<int>(n, 0));

        vector<pair<int, int>>direction = {{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};

        Q.push({0, 0});
        int ans=0;
        distance[0][0] = 1;
        
        while(!Q.empty()){
            
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();

            if(x==n-1 and y==n-1)return distance[x][y];
            
            for(auto dir: direction){
                int nx = dir.first + x;
                int ny = dir.second + y;

                if(nx>=0 and nx<n and ny>=0 and ny<n and distance[nx][ny]==0 and arr[nx][ny]==0){
                    Q.push({nx, ny});
                    distance[nx][ny] = 1 + distance [x][y];
                }
            }
        }
        return -1;
    }
};