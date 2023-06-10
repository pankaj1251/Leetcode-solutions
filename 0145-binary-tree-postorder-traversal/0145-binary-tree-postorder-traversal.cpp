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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;

        TreeNode *curr = root, *last=NULL;

        while(!st.empty() || curr!=NULL){
            if(curr != NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode* temp = st.top();

                if(temp->right != NULL and last != temp->right){
                    curr = temp->right;
                }
                else{    
                    ans.push_back(temp->val);
                    last=temp;
                    st.pop();
                }

            }
        }

        return ans;
    }
};