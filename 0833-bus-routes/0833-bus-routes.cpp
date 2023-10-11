class Solution {
public:
    int func(vector<vector<int>>& routes, unordered_map<int, vector<int>> &bus_stops, int src, int dest){
        if(src==dest)return 0;

        unordered_map<int, bool>vis_stops;

        for(auto &it: bus_stops){
            vis_stops[it.first]=false;
        }

        vector<bool>vis_bus(routes.size(), false);

        queue<pair<int, int>>Q;
        Q.push({src, 0});

        while(!Q.empty()){
            auto front = Q.front(); Q.pop();

            int cur_stop = front.first;
            int count = front.second;

            if(cur_stop==dest)return count;

            for(auto &it: bus_stops[cur_stop]){
                if(!vis_bus[it]){
                    for(auto &x: routes[it]){
                        if(!vis_stops[x]){
                            Q.push({x, count+1});
                            vis_stops[x]=true;
                        }
                    }
                    vis_bus[it]=true;
                }
            }
        }
        return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if(source==target || n==0)return 0;

        unordered_map<int, vector<int>>bus_stops;

        for(int i=0; i<n; i++){
            for(int j=0; j<routes[i].size(); j++){
                int curr_stop = routes[i][j];
                int curr_bus=i;
                bus_stops[curr_stop].push_back(curr_bus);
            }
        }

        return func(routes, bus_stops, source, target);
    }

};