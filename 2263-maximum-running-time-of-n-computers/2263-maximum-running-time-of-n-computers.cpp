class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        long long sum = accumulate(bat.begin(), bat.end(), 0LL);
        
        priority_queue<int>PQ(bat.begin(), bat.end());

        while(PQ.top() > sum/n){
            sum -= PQ.top();
            PQ.pop();
            n--;
        }

        return sum/n;

    }
};