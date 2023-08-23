class Solution {
public:

    static bool comparator(pair<vector<int>, char>&a, pair<vector<int>, char>&b){
        if(a.first==b.first)return a.second<b.second;
        return a.first>b.first;
    }

    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        int sz = votes[0].size();
        vector<vector<int>>umap(26, vector<int>(sz, 0));
        for(auto &voter: votes){
            for(int i=0; i<voter.size(); i++){
                umap[voter[i]-'A'][i]++;
            }
        }

        // for(int i=0; i<26; i++){
        //     for(int j=0; j<umap[i].size(); j++){
        //         cout<<umap[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<pair<vector<int>, char>> table(26);

        for(int i=0; i<26; i++){
            table[i] = {umap[i], (i+'A')};
        }

        sort(table.begin(), table.end(), comparator);

        string ans="";

        for(int i=0; i<min(sz, 26); i++){
            ans += table[i].second;
        }

        return ans;
    }
};