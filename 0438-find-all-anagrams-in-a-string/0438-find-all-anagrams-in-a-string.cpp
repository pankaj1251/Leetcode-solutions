class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size())return ans;

        vector<int>P_map(26, 0), hash(26, 0);
        int window = p.size();
        int n = s.size();

        int right=0, left=0;

        while(right < window)
        {
            P_map[p[right] - 'a']++;
            hash[s[right] - 'a']++;
            right++;
        }

        right--;
        
        while(right < n){
            if(P_map == hash){
                ans.push_back(left);
            }
            right++;
            if(right != n){
                hash[s[right] - 'a']++;
            }
            hash[s[left] - 'a']--;
            left++;
        }

        return ans;
    }
};