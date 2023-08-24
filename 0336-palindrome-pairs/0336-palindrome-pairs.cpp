//https://leetcode.com/problems/palindrome-pairs/solutions/2585974/4-cases-c-ac-solution/
class Solution {
public:
    bool isPal(string s, int st, int en){
        while(st<en){
            if(s[st++] != s[en--])return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& arr) {
        int n = arr.size();
        vector<vector<int>>ans;
        unordered_map<string, int>umap;
        set<int>sz;
        for(int i=0; i<n; i++){
            umap[arr[i]]=i;
            sz.insert(arr[i].size());
        }

        for(int i=0; i<n; i++){
            string str=arr[i];
            int len=str.size();

            //case I: if str contain only one char then find empty string in map to concatenate.
            //as arr does not contain duplicates, our only option is to find empty strings. 
            if(len==1){
                if(umap.count("") and umap[""] != i){
                    ans.push_back({i, umap[""]});
                    ans.push_back({umap[""], i});
                }
                continue;
            }

            string rev = arr[i];
            reverse(rev.begin(), rev.end());

            //case II: if reverse of string is present in map.
            if(umap.count(rev) and umap[rev] != i){
                ans.push_back({i, umap[rev]}); //as we are traersing , we will eventually cover the reverse of this string also.
            }

            for(auto size: sz){
                if(size==len)break;

                //case III
                if(isPal(rev, 0, len-1-size)){
                    string str1 = rev.substr(len-size);
                    if(umap.count(str1)){
                        ans.push_back({i, umap[str1]});
                    }
                }

                //case IV
                if(isPal(rev, size, len-1)){
                    string str2 = rev.substr(0, size);
                    if(umap.count(str2)){
                        ans.push_back({umap[str2], i});
                    }
                }
            }
        }

        return ans;
    }
};