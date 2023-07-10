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
    bool isleaf(TreeNode* root){
        return (!root->left and !root->right);
    }

    void func(TreeNode* root, int &ans){
        if(root==NULL || isleaf(root))return;

        func(root->left, ans);

        if(root->left != NULL and isleaf(root->left))ans += root->left->val;

        func(root->right, ans);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        func(root, ans);

        return ans;
    }
};