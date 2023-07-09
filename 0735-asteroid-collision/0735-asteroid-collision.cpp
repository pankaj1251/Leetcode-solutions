class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;  
        vector<int>ans;

        for(int i=0; i<n; i++)
        {
            if(arr[i]>0)st.push(i);
        
            else
            {
                while(st.size() and abs(arr[i]) > arr[st.top()]){
                    st.pop();
                }
                if(st.empty())ans.push_back(arr[i]);
                else if(arr[st.top()]==abs(arr[i]))st.pop();
            }
        } 

        vector<int> temp;
        while(st.size())
        {
            temp.push_back(arr[st.top()]);
            st.pop();   
        }
        for(int i = temp.size() - 1; i >=0 ; i--)ans.push_back(temp[i]); //we can't directly reverse the ans array as there are already some elements present in it before we empty the stack. 
        temp.clear();
        return ans;
    }
};