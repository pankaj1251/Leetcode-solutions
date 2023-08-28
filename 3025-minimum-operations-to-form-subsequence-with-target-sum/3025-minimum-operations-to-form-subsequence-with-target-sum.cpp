class Solution {
public:
    int minOperations(vector<int>& arr, int target) {
        priority_queue<int>PQ;
        long long sum=0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum += arr[i];
            PQ.push(arr[i]);
        }

        int ans=0;

        while(target>0)
        {
            int top = PQ.top();
            PQ.pop();
            sum -= top;

            if(top <= target){
                target -= top;
            }

            else if(top>target and sum<target){
                ans++;
                sum += top;
                PQ.push(top/2);
                PQ.push(top/2);
            }

            if(PQ.empty() and target != 0)return -1;
        }

        return ans;
    }
};