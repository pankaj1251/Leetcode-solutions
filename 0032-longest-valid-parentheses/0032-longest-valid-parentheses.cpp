class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int i=0, j=0, ans=0, c=0;
        stack<int>st;
        st.push(-1); //for else condition.
        while(i<n){
            
            if(s[i]=='(')
            {
                st.push(i);
            }
            else {
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    ans = max(ans, i-st.top());
                }
            }
            i++;
        }
        ans = max(ans, c);

        return ans;
    }
};