class DSU{
public:
    vector<int>size, parent, rank;

    DSU(int n){
        size.resize(n+1, 1);
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++)parent[i]=i;
    }

    int findPar(int node){
        if(node==parent[node])return node;
        return parent[node] = findPar(parent[node]);
    }

    void USize(int u, int v){
        int par_u = findPar(u);
        int par_v = findPar(v);
        if(par_u == par_v)return;

        if(size[par_v] < size[par_u]){
            parent[par_v]=par_u;
            size[par_u]+=size[par_v];
            size[par_v]=0;
        }
        else{
            parent[par_u]=par_v;
            size[par_v]+=size[par_u];
            size[par_u]=0;
        }
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& arr) {
        int n=arr.size();
        int m = arr[0].size();
        DSU ds(m*n);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1)
                {
                    int cellIdx = m*i+j;
                    
                    while(j<m){
                        if(arr[i][j]==1)
                        {
                            int neighCellIdx = m*i+j;

                            ds.USize(cellIdx, neighCellIdx);
                        }
                        j++;
                    }
                }
            }
        }

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(arr[i][j]==1)
                {
                    int cellIdx = m*i+j;

                    while(i<n){
                        if(arr[i][j]==1)
                        {
                            int neighCellIdx = m*i+j;

                            ds.USize(cellIdx, neighCellIdx);
                        }
                        i++;
                    }
                }
            }
        }

        int ans=0;

        for(int i=0; i<=n*m; i++){
            if(ds.size[i] > 1)ans += ds.size[i];
        }

        return ans;
    }
};