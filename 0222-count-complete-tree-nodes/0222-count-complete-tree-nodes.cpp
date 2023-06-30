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
    int left(TreeNode* root){
        if(root==NULL)return 0;
        int ans=0;
        while(root){
            root=root->left;
            ans++;
        }
        return ans;
    } 
    
    int right(TreeNode* root){
        if(root==NULL)return 0;
        int ans=0;
        while(root){
            root=root->right;
            ans++;
        }
        return ans;
    } 

    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;

        int lh = left(root);
        int rh = right(root);

        if(lh == rh)return pow(2, lh)-1;

        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};