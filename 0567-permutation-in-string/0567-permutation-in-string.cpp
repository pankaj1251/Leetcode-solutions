class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s2.size() < s1.size())return false;

        unordered_map<char, int>mp1, mp2;
        for(int i=0; i<s1.length(); i++){
            mp1[s1[i]]++;
        }

        int n = s2.size();
        int j=0, i=0;
        while(j<s1.length()){
            mp2[s2[j]]++;
            j++;
        }

        if(mp1==mp2)return true;
        while(j<n){
            mp2[s2[i]]--;
            if(mp2[s2[i]]==0)mp2.erase(s2[i]);
            mp2[s2[j]]++;
            i++, j++;
            if(mp1==mp2)return true;
        }

        return false;
    }
};