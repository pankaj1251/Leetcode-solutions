class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=0, k=0;
        int m = s.length(), n = t.length();
        
        for(int i=0; i<m; i++){
            if(s[i]=='#'){
                k--;
                k=max(0, k);
            }
            else{
                s[k]=s[i];
                k++;
            }
        }
        
        int p=0;
        for(int i=0; i<n; i++){
            if(t[i]=='#'){
                p--;
                p=max(0, p);
            }
            else{
                t[p]=t[i];
                p++;
            }
        }
        
        if(k!=p)return false;
        else{
            for(int i=0; i<k; i++){
                if(s[i] != t[i])return false;
            }
            return true;
        }
    }
};