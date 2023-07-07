class Solution {
public:
    int func(string str, char ch, int k){
        string temp = str;
        int n = str.size(), i=0, j=0, c=0;
        int ans=1;

        while(j<n)
        {
            if(temp[j]==ch)c++;

            ans = max(ans, j-i);

            while(c>k and i<j)
            {
                if(temp[i]==ch)c--;
                i++;
            }
            j++;
        }
        
        ans = max(ans, j-i);

        return ans;
    }

    int maxConsecutiveAnswers(string str, int k) {
        int ans=1;
        int i=0, j=0, n = str.size();

        int t = func(str, 'T', k);
        int f = func(str, 'F', k);

        return max(t, f);
    }
};