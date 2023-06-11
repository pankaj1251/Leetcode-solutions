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
    vector<int> levelOrder(TreeNode* root){
        if(root==NULL)return {};

        vector<int>ans;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int sz = Q.size();
            vector<int>level;
            while(sz--){
                TreeNode* temp = Q.front();
                Q.pop();
                level.push_back(temp->val);
                if(temp->left)Q.push(temp->left);
                if(temp->right)Q.push(temp->right);
            }
            ans.push_back(level.back());
        }

        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        return levelOrder(root);
    }
};