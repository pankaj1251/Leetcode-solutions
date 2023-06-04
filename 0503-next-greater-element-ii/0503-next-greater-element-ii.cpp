class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp(2*n);
        for(int i=0; i<2*n; i++){
            temp[i] = arr[i%n];
        }

        stack<pair<int, int>>st;
        vector<int>nge(2*n, -1);
        
        for(int i=0; i<2*n; i++){

            while(!st.empty() and st.top().first < temp[i]){
                nge[st.top().second] = temp[i];
                st.pop();
            }

            st.push({temp[i], i});
        }

        while(!st.empty()){
            st.pop();
            nge.push_back(-1);
        }

        nge.resize(n);
        return nge;
    }
};