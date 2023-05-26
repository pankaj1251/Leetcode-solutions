class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int i=0, j=0, ans=0, end = s.length()-1;
        unordered_map<char, int>umap;

        while(j<s.length())
        {
            umap[s[j]]++;

            while(umap['a'] && umap['b'] && umap['c']){
                ans = ans + end - j + 1;

                umap[s[i]]--;
                i++;
            }
            
            j++;
        }

        return ans;
    }
};