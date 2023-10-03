class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int>arr(26, 0);
        arr[s[0]-'a']=1;
        int prev=1;
        int ans=1;
        for(int i=1; i<n; i++){
            if((s[i-1]-'a'+1)%26 == s[i]-'a')prev++;
            else prev=1;

            if(arr[s[i]-'a'] < prev){
                ans += prev-arr[s[i]-'a'];
                arr[s[i]-'a'] = prev; //this is how we calculate no of substrings.
            }
        }
        return ans;
    }
};