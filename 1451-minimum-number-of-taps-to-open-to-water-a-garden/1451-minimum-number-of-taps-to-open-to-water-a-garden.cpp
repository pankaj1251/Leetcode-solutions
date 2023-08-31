class Solution {
public:
    int minTaps(int n, vector<int>& arr) 
    {
        int m = arr.size();
        vector<vector<int>>interval(m, vector<int>(2));
        for(int i=0; i<m; i++){
            interval[i][0] = i - arr[i];
            interval[i][1] = i + arr[i];
        }

        sort(interval.begin(), interval.end());
        // for(int i=0; i<m; i++){
        //     cout<<interval[i][0]<<" "<<interval[i][1]<<endl;
        // }
        
        int ans=0;
        int st=0, en=0, i=0;
        
        while(en<n)
        {
            for(; i<m and interval[i][0]<=st; i++)
            {
                en = max(en, interval[i][1]);
            }
            if(st==en)return -1;
            st=en;
            ans++;
        }

        return ans;
    }
};