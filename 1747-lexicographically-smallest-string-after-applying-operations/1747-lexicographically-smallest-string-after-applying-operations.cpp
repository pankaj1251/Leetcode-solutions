class Solution {
public:
    string rotate(string& s, int b){
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+b);
        reverse(s.begin()+b, s.end());
        return s;
    }

    string add(string &s, int a){
        for(int i=1; i<s.length(); i+=2){
            char &ch = s[i];
            ch = (ch - '0' + a) % 10 + '0';
        }

        return s;
    }

    void dfs(string s, int a, int b, unordered_set<string>&vis, string &ans){
        if(vis.find(s) != vis.end())return;

        ans = min(s, ans);
        vis.insert(s);

        dfs(rotate(s, b), a, b, vis, ans);
        dfs(add(s, a), a, b, vis, ans);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string>vis;
        string ans=s;
        dfs(s, a, b, vis, ans);

        return ans;
    }
};