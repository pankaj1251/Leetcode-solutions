class Solution {
public:
    void func(string &s, set<string>st, int idx, string str, vector<string>&ans){
        if(idx==s.length()){
            str.pop_back(); // to delete last strings leading whitespace.
            ans.push_back(str);
            return;
        }

        for(int i=idx; i<s.length(); i++){
            string temp = s.substr(idx, i-idx+1);

            if(st.find(temp) != st.end())
                func(s, st, i+1, str + temp + ' ', ans);
            
        }
    }

    vector<string> wordBreak(string s, vector<string>& words) {
        int n = s.length();
        vector<string>ans;
        set<string>st(words.begin(), words.end());
        func(s, st, 0, "", ans);
        return ans;
    }
};