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
    TreeNode* lca(TreeNode* root, TreeNode* t1, TreeNode* t2){
        if(root==NULL)return root;
        if(root->val==t1->val || root->val == t2->val)return root;

        TreeNode* left = lca(root->left, t1, t2);
        TreeNode* right = lca(root->right, t1, t2);

        if(left and right)return root;

        return left==NULL ? right: left;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>Q;
        Q.push(root);
        vector<TreeNode*>nodes;

        while(!Q.empty()){
            int sz = Q.size();
            vector<TreeNode*>temp;
            while(sz--){
                TreeNode* node = Q.front();
                Q.pop();
                temp.push_back(node);

                if(node->left)Q.push(node->left);
                if(node->right)Q.push(node->right);
            }
            nodes = temp;
        }


        TreeNode* ans = nodes[0];
        for(auto it: nodes) ans = lca(root, ans, it);
        return ans;
    }
};