class TopVotedCandidate {
public:
    vector<int>T;
    vector<int>ans;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        T = times;
        int max_p = -1;
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[persons[i]]++;
            if(mp[max_p] <= mp[persons[i]]){
                max_p = persons[i];
            }
            ans.push_back(max_p);
        }
    }
    
    int q(int t) {
        int idx = (upper_bound(T.begin(), T.end(), t) - T.begin())-1;

        return ans[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */