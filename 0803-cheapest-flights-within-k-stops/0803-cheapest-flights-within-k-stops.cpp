class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);

        for(int i=0; i<arr.size(); i++){
            adj[arr[i][0]].push_back({arr[i][1], arr[i][2]});
        }

        queue<pair<int, pair<int, int>>>Q;
        vector<int>dist(n+1, 1e9);

          //stops  node  dist
        Q.push({0, {src, 0}});

        while(!Q.empty())
        {
            int stops = Q.front().first;
            int source = Q.front().second.first;
            int distance = Q.front().second.second;
            Q.pop();

            if(stops>k)continue;
            
            for(auto node: adj[source])
            {
                int new_source = node.first;
                int new_distance = node.second;
                
                if(distance + new_distance < dist[new_source] and k>=stops){
                    dist[new_source] = distance + new_distance;
                    Q.push({stops+1, {new_source, dist[new_source]}});
                }
            }
        }

        return dist[dst]==1e9 ? -1 : dist[dst];
    }
};