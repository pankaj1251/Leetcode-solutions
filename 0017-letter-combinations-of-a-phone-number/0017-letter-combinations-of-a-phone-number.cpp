class Solution {
public:
    vector<string> alph= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};

    void func(string arr, int i, int n, vector<string>&ans){
        if(i>=n)return;
        
        if(ans.empty()){
            string s = alph[arr[i]-'0'];
            for(int k=0; k<s.length(); k++) {ans.push_back(string(1, s[k]));}
            func(arr, i+1, n, ans);
        }
        else{
            string s = alph[arr[i]-'0'];
            vector<string>temp;
            for(int j=0; j<ans.size(); j++){
                string xx = ans[j];
                for(int k=0; k<s.length(); k++){
                    xx += s[k];
                    temp.push_back(xx);
                    xx.pop_back();
                }
            }
            ans=temp;
            func(arr, i+1, n, ans);
        }

    }
    vector<string> letterCombinations(string arr) {
        vector<string>ans;
        int sz = arr.size();
        func(arr, 0, sz, ans);  
        return ans;
    }
};