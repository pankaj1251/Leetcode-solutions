class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<int>freq(26, 0);

        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }   
        
        unordered_map<int, int>mp;
        set<int>st;
        int ans=0;

        sort(freq.begin(), freq.end(), greater<int>());

        for(int i=0; i<26; i++){
            if(freq[i]==0)break;
            st.insert(freq[i]);
        }

        for(int i=1; i<26; i++){
            if(freq[i]==0)break;
            if(freq[i]==freq[i-1]){
                int temp = freq[i];
                while(st.find(temp) != st.end()){
                    if(temp==0)break;
                    temp--;
                }
                st.insert(temp);
                ans += abs(freq[i]-temp);
            }
        }

        return ans;
    }
};