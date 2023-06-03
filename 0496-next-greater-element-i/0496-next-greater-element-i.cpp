class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int>st;
        unordered_map<int, int>umap;

        for(int i=0; i<n2; i++){
            while(!st.empty() and st.top() < nums2[i]){
                umap[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        while(!st.empty()){umap[st.top()] = -1; st.pop();}

        vector<int>ans(n1);

        for(int i=0; i<n1; i++){
            ans[i] = umap[nums1[i]];
        }

        return ans;
    }
};