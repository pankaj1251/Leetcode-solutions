class Disjoint{
public:
    vector<int>parent, rank, size;
    Disjoint(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++)parent[i]=i;
    }

    int uPar(int node){
        if(node==parent[node])return node;

        return parent[node] = uPar(parent[node]);
    }

    void UnionByRank(int u, int v){
        int par_u = uPar(u);
        int par_v = uPar(v);

        if(par_u==par_v)return;

        if(rank[par_u] < rank[par_v]){
            parent[par_u]=par_v;
        }
        else if(rank[par_v] < rank[par_u]){
            parent[par_v]=par_u;
        }
        else{
            parent[par_v]=par_u;
            rank[par_v]++;
        }
    }

    void UnionBySize(int u, int v){
        int par_u = uPar(u);
        int par_v = uPar(v);

        if(par_u==par_v)return;

        if(size[par_u] < size[par_v]){
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
        else{
            parent[par_v]=par_u;
            size[par_u] += size[par_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& arr) {
        int extra=0; 
        Disjoint ds(n);

        for(auto &it: arr){
            int u = it[0];
            int v = it[1];

            if(ds.uPar(u) == ds.uPar(v))extra++;
            else ds.UnionBySize(u, v);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(ds.parent[i]==i)ans++;
        }

        return extra>=ans-1? ans-1: -1;
    }
};