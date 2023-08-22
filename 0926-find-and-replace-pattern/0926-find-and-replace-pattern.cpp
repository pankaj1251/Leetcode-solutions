class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        int m= pattern.size();
        vector<string>ans;

        for(int i=0; i<n; i++){
            string str=words[i];
            int sz=str.size();
            if(sz!=m)continue;
            vector<char>check(26, -1);
            bool flag=true;
            set<char>st;
            for(int j=0; j<sz; j++){
                if(check[pattern[j]-'a']==-1 and st.find(str[j])==st.end()){
                    check[pattern[j]-'a'] = str[j];
                    st.insert(str[j]);
                }
                else if(check[pattern[j]-'a'] != str[j]){
                    flag=false;
                    break;
                }
            }
            if(flag==true)ans.push_back(words[i]);
        }
        return ans;
    }
};