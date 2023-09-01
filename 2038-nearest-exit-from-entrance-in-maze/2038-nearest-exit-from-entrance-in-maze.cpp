class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<char>> vis = maze;

        queue<pair<int , pair<int, int>>> q;

        int ans=0;
        q.push({ ans ,{entrance[0] , entrance[1]}});
        vis[entrance[0]][entrance[1]] = '+';   // mark entrance as visited

        int delrow[] = {-1 , 0 , +1 , 0};
        int delcol[] = {0 , +1 , 0 , -1};

        while(q.empty()==false){
            int sz = q.size();
            while(sz--){
                int dist= q.front().first;
                int r = q.front().second.first;
                int c = q.front().second.second;
                q.pop();

                for(int i=0 ; i<4 ; i++)
                {
                    int nrow = r + delrow[i];
                    int ncol = c + delcol[i];
                
                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]=='.'){
                        if(nrow == n-1 || nrow==0 || ncol==m-1 || ncol==0){       
                            return dist+1;
                        }

                        q.push({dist+1 , {nrow , ncol}});
                        vis[nrow][ncol] = '+';
                    }
                }

            }
        }
        return -1;
    }
};