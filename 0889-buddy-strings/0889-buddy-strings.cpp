class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())return false;
        unordered_map<char, int>umap;
        if(s==goal){
            for(auto &it: s)umap[it]++;
            for(auto &it:umap)if(it.second>=2)return true;
            return false;
        }

        int i=0, j=s.size()-1, n=s.length();
        int first=-1, second=-1;
        while(i<n){
            if(s[i] != goal[i]){
                break;
            }
            i++;
        }
        if(i==n)return true;

        while(j>i){
            if(s[j] != goal[j]){
                break;
            }
            j--;
        }

        swap(s[i], s[j]);

        return s==goal;
    }
};