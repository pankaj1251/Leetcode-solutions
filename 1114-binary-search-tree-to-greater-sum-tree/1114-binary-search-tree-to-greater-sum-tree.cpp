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
    void inorder(TreeNode* root, int &sum){
        if(root==NULL)return;

        inorder(root->left, sum);
        sum += root->val;
        inorder(root->right, sum);
    }

    void func(TreeNode* root, int &sum, int &temp){
        if(root==NULL)return;

        func(root->left, sum, temp);

        int xx = root->val;
        root->val = sum - temp;
        temp += xx;
        
        func(root->right, sum, temp);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0, temp=0;
        inorder(root, sum);
        
        func(root, sum, temp);    
        return root;
    }
};