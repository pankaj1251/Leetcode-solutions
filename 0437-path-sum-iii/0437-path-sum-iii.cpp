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
    int ans=0;
    void func(TreeNode* root, long long int target){
        if(root==NULL)return;

        if(root->val==target)
            ans++;
        

        func(root->left, target-root->val);
        func(root->right, target - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;

        func(root, targetSum);

        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return ans;
    }
};