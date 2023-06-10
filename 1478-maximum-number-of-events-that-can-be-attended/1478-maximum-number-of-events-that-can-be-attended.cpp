class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue <int, vector<int>, greater<int> > PQ;
        sort(events.begin(),events.end());
        int total_days = 0;
        for(int i = 0;i<events.size();i++){
            total_days = max(total_days, events[i][1]);
        }
        // cout<<total_days<<endl;
        int day = 1, ans = 0, i = 0;
        int n = events.size();

        while(day <= total_days)
        {
            if(i< n && PQ.empty()){
                day = events[i][0];
            }
            while (i < n and events[i][0] <= day){
                PQ.push(events[i][1]);
                i += 1;
            }
            while (!PQ.empty() && PQ.top() < day)
                PQ.pop();

            if (!PQ.empty()){
                PQ.pop();
                ans += 1;
            }
			else if (i >= n)
                break ;
            day += 1;
        }
        return ans;
    }
};