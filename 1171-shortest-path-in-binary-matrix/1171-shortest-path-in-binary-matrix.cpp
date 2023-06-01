class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& arr) {
        int n = arr.size();
        if(arr[0][0] != 0 || arr[n-1][n-1]!=0)return -1;
        
        queue<pair<int, int>>Q;
        vector<vector<int>>vis(n, vector<int>(n, 0));

        Q.push({0, 0});
        int ans=0;
        vis[0][0] = 1;
        while(!Q.empty()){
            
            int xx = Q.front().first;
            int yy = Q.front().second;
            Q.pop();

            if(xx==n-1 and yy==n-1)return vis[xx][yy];
            
            if(yy-1>=0 and xx+1<n and arr[xx+1][yy-1]==0 and vis[xx+1][yy-1]==0){
                Q.push({xx+1, yy-1});
                vis[xx+1][yy-1] = 1 + vis[xx][yy];    
            }
            if(yy+1<n and arr[xx][yy+1]==0 and vis[xx][yy+1]==0){
                Q.push({xx, yy+1});
                vis[xx][yy+1] = 1 + vis[xx][yy];    
            }
            if(yy+1<n and xx+1<n and arr[xx+1][yy+1]==0 and vis[xx+1][yy+1]==0){
                Q.push({xx+1, yy+1});
                vis[xx+1][yy+1] = 1 + vis[xx][yy];    
            }
            if(xx+1<n and arr[xx+1][yy]==0 and vis[xx+1][yy]==0){
                Q.push({xx+1, yy});
                vis[xx+1][yy] = 1 + vis[xx][yy];    
            }
            if(yy-1>=0 and arr[xx][yy-1]==0 and vis[xx][yy-1]==0){
                Q.push({xx, yy-1});
                vis[xx][yy-1] = 1 + vis[xx][yy];    
            }
            if(xx-1>=0 and yy-1>=0 and arr[xx-1][yy-1]==0 and vis[xx-1][yy-1]==0){
                Q.push({xx-1, yy-1});
                vis[xx-1][yy-1] = 1 + vis[xx][yy];    
            }
            if(xx-1>=0 and arr[xx-1][yy]==0 and vis[xx-1][yy]==0){
                Q.push({xx-1, yy});
                vis[xx-1][yy] = 1 + vis[xx][yy];    
            }
            if(xx-1>=0 and yy+1<n and arr[xx-1][yy+1]==0 and vis[xx-1][yy+1]==0){
                Q.push({xx-1, yy+1});
                vis[xx-1][yy+1] = 1 + vis[xx][yy];    
            }

        }
        return -1;
    }
};