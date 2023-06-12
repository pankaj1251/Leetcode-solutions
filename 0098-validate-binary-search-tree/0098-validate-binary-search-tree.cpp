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
    bool check(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
        if(root==NULL)return true;

        if((minNode!=NULL and root->val <= minNode->val) || (maxNode!=NULL and root->val >= maxNode->val))        
            return false;

        return check(root->left, minNode, root) and check(root->right, root, maxNode);
    }
    bool isValidBST(TreeNode* root) 
    {
        TreeNode* minNode = new TreeNode(-1e9);
        TreeNode* maxNode = new TreeNode(1e9);

        return check(root, NULL, NULL);
    }
};