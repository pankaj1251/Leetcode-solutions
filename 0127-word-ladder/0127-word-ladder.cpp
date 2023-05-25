class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(int i=0; i<wordList.size(); i++){
            st.insert(wordList[i]);
        }

        if(st.find(endWord) == st.end())return 0;

        int ans=0;
        queue<string>Q;
        Q.push(beginWord);
        
        while(!Q.empty())
        {
            ans++;
            int sz = Q.size();
            
            while(sz--)
            {
                string str = Q.front();
                Q.pop();
                // cout<<str<<" ";

                int n = str.size();
                for(int i=0; i<n; i++)
                {
                    string temp = str;

                    for(char ch='a'; ch<='z'; ch++)
                    {
                        temp[i] = ch;

                        if(str == temp)continue;
                        
                        if(temp == endWord)return ans+1;

                        if(st.find(temp) != st.end())
                        {
                            st.erase(temp);
                            Q.push(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};