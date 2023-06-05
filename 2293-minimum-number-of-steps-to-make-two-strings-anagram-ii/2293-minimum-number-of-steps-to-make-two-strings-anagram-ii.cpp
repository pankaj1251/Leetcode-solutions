class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;

        vector<int>s1(26,0), t1(26,0);

        for(int i=0; i<s.size(); i++){
            s1[s[i]-'a']++;
        }

        
        for(int i=0; i<t.size(); i++){
            t1[t[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(s1[i]>0 and t1[i]>0){
                int temp = min(s1[i], t1[i]);
                s1[i] -= temp;
                t1[i] -= temp;
            }
        }

        for(int i=0;i<26;i++){
            ans += t1[i] + s1[i];
        }

        return ans;
    }
};