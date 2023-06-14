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
    int func(TreeNode* root, int &prev, int &diff){
        if(root==NULL)return INT_MAX;

        func(root->left, prev, diff);

        if(prev >= 0) diff = min(diff, root->val-prev);
        prev = root->val;

        func(root->right, prev, diff);

        return diff;
    }
    int getMinimumDifference(TreeNode* root) {
        if(!root)return 0;

        int res=INT_MAX, prev=-1;

        func(root, prev, res);

        return res;
    }
};