class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int>columns(n);
        for(int i=0; i<n; i++){
            columns[i]=i;
        }

        vector<pair<int, int>>indexes(n*n + 1); //storing indexes of each cell of arr, so that we can jump directly to that index.
        int c=1;
        for(int i=n-1; i>=0; i--){
            for(auto j: columns){
                indexes[c++] = {i, j};
            }
            reverse(columns.begin(), columns.end()); 
        }

        vector<int>dist(n*n+1, -1);
        
        queue<int>Q;
        Q.push(1);
        dist[1] = 0;

        while(!Q.empty())
        {
            int idx = Q.front();
            Q.pop();

            for(int i=idx+1; i<= min(idx+6, n*n); i++)
            {
                auto [row, col] = indexes[i];
                
                int destination = arr[row][col] != -1 ? arr[row][col] : i;

                if(dist[destination] == -1){
                    dist[destination] = dist[idx]+1;
                    Q.push(destination);
                }
            }
        }
        return dist[n*n];
    }
};