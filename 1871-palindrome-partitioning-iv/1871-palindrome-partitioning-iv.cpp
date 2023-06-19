class Solution {
public:
    bool isPal(string &s,int st, int e){
        while(st<e){
            if(s[st++] != s[e--])return false;
        }
        return true;
    }
    
    bool checkPartitioning(string s) {
        int n = s.length();

        for(int i=2; i<n; i++){
            if(isPal(s, i, s.length()-1)){
                for(int j=1; j<i; j++)
                {
                    if(isPal(s, 0, j-1) and isPal(s, j, i-1))return true;
                }   
            }
        }
        return false;
    }
};