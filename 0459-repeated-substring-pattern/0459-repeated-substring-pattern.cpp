class Solution {
public:

    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        
        for(int i=1; i<=n/2; i++){
            if(n%i==0){
                string substr = s.substr(0, i);
                string dup="";
                for(int j=0; j<n/i; j++)dup += substr;

                if(dup==s)return true;
            }
        }

        return false;
    }
};