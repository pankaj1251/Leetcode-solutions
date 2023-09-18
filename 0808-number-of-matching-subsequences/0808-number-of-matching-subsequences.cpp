class Solution {
public:
    map<char,vector<int>> count;
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        for(int i=0;i<s.size();i++){
            count[s[i]].push_back(i);
        }

        int ans=0;
        for(auto& x:words)
        {
            int greater_idx=-1;//find element greater thn this index
            int flag=true;//flag bit

            for(int j=0;j<x.size();j++)
            {
                if(count.find(x[j])==count.end()){flag=false;break;}
                if(upper_bound(count[x[j]].begin(),count[x[j]].end(),greater_idx)==count[x[j]].end()){
                    flag=false;  //if greater position not found. 
                    break;
                }

                greater_idx=count[x[j]][upper_bound(count[x[j]].begin(),count[x[j]].end(),greater_idx)-count[x[j]].begin()];//updating search index
            }
            if(flag==true)ans++;
        }
        return ans;
    }
};