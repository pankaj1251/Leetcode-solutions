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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;

        queue<TreeNode*>Q;
        Q.push(root);

        while(!Q.empty())
        {
            int maxm = INT_MIN;
            int sz = Q.size();
            while(sz--)
            {
                TreeNode* temp = Q.front();
                Q.pop();
                maxm = max(maxm, temp->val);
                if(temp->left)Q.push(temp->left);
                if(temp->right)Q.push(temp->right);
            }
            ans.push_back(maxm);
        }
        return ans;
    }
};