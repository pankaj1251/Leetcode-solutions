/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;

        TreeNode* curr = root;

        while(!st.empty() || curr!=NULL){
            if(curr != NULL){
                ans.push_back(curr->val);
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode* temp = st.top();
                st.pop();

                curr=temp->right;
            }
        }

        return ans;
    }
};