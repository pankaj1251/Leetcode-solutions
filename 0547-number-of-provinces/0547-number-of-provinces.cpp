class Disjoint{
public:
    vector<int>rank, size, parent;

    Disjoint(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0; i<=n; i++)parent[i]=i;
    }

    int find_Upar(int node){
        if(node==parent[node])return node;
        return parent[node] = find_Upar(parent[node]);
    }

    void UnionByRank(int u ,int v){
        int Upar_u = find_Upar(u);
        int Upar_v = find_Upar(v);

        if(Upar_u==Upar_v)return;

        if(rank[Upar_u] < rank[Upar_v]){
            parent[Upar_u] = Upar_v;
        }
        else if(rank[Upar_v]<rank[Upar_u]){
            parent[Upar_v] = Upar_u;
        }
        else{
            parent[Upar_v] = Upar_u;
        }
    }
};
class Solution {
public:
    

    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();

        Disjoint ds(n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]==1){
                    ds.UnionByRank(i, j);
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(ds.parent[i]==i)ans++;
        }

        return ans;
    }
};