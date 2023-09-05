class DSU{
    public:
    vector<int> size, parent, rank;
    DSU(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }

    int findPar(int node){
        if(node==parent[node])return node;
        return parent[node] = findPar(parent[node]);
    }

    void UnionR(int u, int v){
        int u_par = findPar(u);
        int v_par = findPar(v);

        if(u_par==v_par)return;

        if(rank[u_par]<rank[v_par]){
            parent[u_par] = v_par;
        }
        else if(rank[v_par]<rank[u_par]){
            parent[v_par] = u_par;
        }
        else{
            parent[v_par] = u_par;
            rank[u_par]++;
        }
    }

    void UnionS(int u, int v){
        int u_par = findPar(u);
        int v_par = findPar(v);

        if(u_par==v_par)return;

        if(size[u_par]<size[v_par]){
            parent[u_par] = v_par;
            size[v_par]+=size[u_par];

        }
        else{
            parent[v_par] = u_par;
            size[u_par]+=size[v_par];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        
        int n = arr.size();
        DSU ds(n);

        //add components to unionSet
        unordered_map<string, int>connect_components;

        for(int i=0; i<n; i++){
            for(int j=1; j<arr[i].size(); j++){
                string mail = arr[i][j];
                if(connect_components.find(mail) == connect_components.end()){
                    connect_components[mail]=i;
                }
                else{
                    ds.UnionS(i, connect_components[mail]);
                }
            }
        }

        //merge mails
        vector<string>mergedMail[n];
        for(auto &it: connect_components){
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergedMail[node].push_back(mail);
        }

        //ans
        vector<vector<string>>ans;

        for(int i=0; i<n; i++){
            if(mergedMail[i].size()==0)continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string>temp;
            temp.push_back(arr[i][0]);
            for(auto &it: mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};