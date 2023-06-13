class Solution {
public:
    vector<int> xx = {-1, 0, 1, 0};
    vector<int> yy = {0, 1, 0, -1};

    void bfs(vector<vector<int>>& arr, vector<vector<int>>&ans)
    {
        int count=0;
        queue<pair<int, int>>Q;

        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr[0].size(); j++){
                if(arr[i][j]==0){
                    Q.push({i, j});
                    ans[i][j]=0;    
                }
            }
        }

        while(!Q.empty())
        {
            int ii = Q.front().first;
            int jj = Q.front().second;
            Q.pop();

            for(int i=0; i<4; i++){
                int ni = ii + xx[i];
                int nj = jj + yy[i];

                if(ni>=0 and ni<arr.size() and nj>=0 and nj<arr[0].size() and ans[ni][nj]==-1){
                    ans[ni][nj] = 1 + ans[ii][jj];
                    Q.push({ni, nj});
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) {
        vector<pair<int, int>>ones;
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>>ans(n, vector<int>(m, -1));
    
        bfs(arr, ans);

        return ans;
    }
};