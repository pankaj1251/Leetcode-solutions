class TreeAncestor {
public:
    vector<vector<int>>table;

    TreeAncestor(int m, vector<int>& parent) 
    {
        int n = parent.size();
        table.resize(20, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            table[0][i] = parent[i];
        }

        for(int i=1; i<20; i++){
            for(int j=0; j<n; j++)
            {
                int node_par = table[i-1][j];
            
                if(node_par != -1)
                    table[i][j] = table[i-1][node_par];
            }
        }


    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0; i<20; i++){
            int mask = (1<<i);
            if(k&mask){
                node = table[i][node];
                if(node==-1)return node;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */