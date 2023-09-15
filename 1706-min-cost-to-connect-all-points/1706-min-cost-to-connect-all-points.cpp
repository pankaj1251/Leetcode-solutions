class DSU{
public:
    vector<int>parent, size, rank;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1);

        for(int i=0; i<=n; i++)parent[i]=i;
    }

    int uPar(int node){
        if(node==parent[node])return node;
        return parent[node]=uPar(parent[node]);
    }

    void URank(int u, int v){
        int u_par = uPar(u);
        int v_par = uPar(v);

        if(u_par==v_par)return;

        if(rank[u_par] < rank[v_par]){
            parent[u_par] = v_par;
        }
        // else if(rank[v_par] < rank[u_par]){
        //     parent[v_par] = u_par;
        // }
        else{
            parent[v_par] = u_par;
        }
    }

    void USize(int u, int v){
        int u_par = uPar(u);
        int v_par = uPar(v);

        if(u_par==v_par)return;

        if(size[u_par] < size[v_par]){
            parent[u_par] = v_par;
            size[u_par] += size[v_par];
        }
        else{
            parent[v_par] = u_par;
            size[v_par] += size[u_par];
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        int ans=0;
        vector<vector<int>>distance;
        for(int i=0; i<n-1; i++){
            int minm=INT_MAX;
            for(int j=i+1; j<n; j++){
                minm = abs(arr[i][0]-arr[j][0])+abs(arr[i][1]-arr[j][1]);
                vector<int>temp = {minm, i, j};
                distance.push_back(temp);
            }
        }

        sort(distance.begin(), distance.end());

        DSU ds(n+1);

        for(int i=0; i<distance.size(); i++){
            if(ds.uPar(distance[i][1]) == ds.uPar(distance[i][2]))continue;
            ans += distance[i][0];
            ds.USize(distance[i][1], distance[i][2]);
        }

        return ans;
    }
};