class Solution {
public:
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};

    void func(vector<vector<int>>& arr, int i, int j, int mid, vector<vector<int>> &vis){
        if(vis[i][j]==1)return;

        vis[i][j]=1;
        int n = arr.size(), m=arr[0].size();

        for(int ii=0; ii<4; ii++){
            int nx = i + dir[ii].first;
            int ny = j + dir[ii].second;

            if(nx<0 || ny<0 || nx>=n || ny>=m)continue;

            if(abs(arr[i][j]-arr[nx][ny]) <= mid){
                func(arr, nx, ny, mid, vis);
            }
        }
    }
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();

        int l=0, r=1e9+2;

        while(l<r){
            int mid = l + (r-l)/2;

            vector<vector<int>>vis(n, vector<int>(m, 0));

            func(arr, 0, 0, mid, vis);

            if(vis[n-1][m-1]==1) r=mid;
            else l = mid + 1;
        }

        return l;
    }
};