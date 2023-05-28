class Solution {
public:
/*
We can derive from the statement that atleast 1 stone will be left on the plane.
So, we can just find the number of disconnected groups using BFS.
For every group, 1 stone will not be picked up.
Then,
Stones picked = Total number of stones - Stones left
*/
    int removeStones(vector<vector<int>>& arr) {
        int n = arr.size();
       
        int ans=0;
        vector<int>vis(n, 0);
        queue<int>Q;

        for(int idx=0; idx<n; idx++){
            if(!vis[idx]){
                Q.push(idx);
                vis[idx]=1;
                ans++;
                while(!Q.empty()){
                    int node = Q.front();
                    Q.pop();

                    for(int i=0; i<n; i++){
                        if(!vis[i] and (arr[node][0]==arr[i][0] or arr[node][1]==arr[i][1])){
                            vis[i]=1;
                            Q.push(i);
                        }
                    }
                }
            }
        }

        return n-ans;
    }
};