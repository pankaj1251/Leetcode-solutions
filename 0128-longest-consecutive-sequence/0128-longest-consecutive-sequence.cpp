class DSU{
public:
    vector<int>rank, parent, size;
    DSU(int n){
       rank.resize(n+1, 0); // 1 based indexing
       parent.resize(n+1);
       size.resize(n+1, 1);

       for(int i=0; i<=n; i++)parent[i]=i;
    }

    //find an Ultimate parent of a node.
    int findUpar(int node){
       if(node == parent[node])return node;

       return parent[node] = findUpar(parent[node]);
    }

    //find union by rank
    void unionByRank(int u, int v){
       int Upar_u = findUpar(u); //ultimate parent of u.
       int Upar_v = findUpar(v); //ultimate parent of v.

       if(Upar_u == Upar_v)return;

       if(rank[Upar_u] < rank[Upar_v]){
           parent[Upar_u] = Upar_v;  //parent of u is v; as rank of v is larger than u. 
       }
       else if(rank[Upar_v] < rank[Upar_u]){
            parent[Upar_v] = Upar_u;
        }
        else{
           parent[Upar_v] = Upar_u; //if rank is same attach anyone to other and increase the rank to which it is getting attached.
           rank[Upar_u]++;
        }
    }
    void unionBySize(int u, int v){
        int Upar_u = findUpar(u); //ultimate parent of u.
        int Upar_v = findUpar(v); //ultimate parent of v.

        if(Upar_u == Upar_v)return;

        if(size[Upar_u] < size[Upar_v]){
            parent[Upar_u] = Upar_v;  //parent of u is v; as rank of v is larger than u. 
            size[Upar_v] += size[Upar_u];
        }
        else{
             parent[Upar_v] = Upar_u;
            size[Upar_u] += size[Upar_v];
        }
   }
};

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>vis;
        DSU ds(n);

        for(int i=0; i<n; i++){
            if(vis.find(arr[i]) != vis.end())continue;

            vis[arr[i]]=i;

            if(vis.find(arr[i]+1) != vis.end()){
                ds.unionBySize(i, vis[arr[i]+1]);
            }
            if(vis.find(arr[i]-1) != vis.end()){
                ds.unionBySize(i, vis[arr[i]-1]);
            }
        }

        int ans=0;
        for(int i=0; i<n; i++){
            if(i==ds.findUpar(i))ans = max(ans, ds.size[i]);
        }

        return ans;
    }
};