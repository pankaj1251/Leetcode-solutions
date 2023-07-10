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
    void func(TreeNode* root, unordered_map<TreeNode*, int> &umap){
        if(root==NULL)return;
        if(!root->left and !root->right){
            umap[root]=root->val;
            return;
        }

        int adjacent=0, not_adjacent=0;

        if(root->left and umap.find(root->left)==umap.end()){
            func(root->left, umap);
            adjacent += umap[root->left];

            if(root->left->left) not_adjacent += umap[root->left->left];
            if(root->left->right) not_adjacent += umap[root->left->right];
        }

        if(root->right and umap.find(root->right)==umap.end()){
            func(root->right, umap);
            adjacent += umap[root->right];

            if(root->right->left) not_adjacent += umap[root->right->left];
            if(root->right->right) not_adjacent += umap[root->right->right];
        }

        umap[root] = max(adjacent, not_adjacent + root->val);
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int>umap;
        func(root, umap);

        return umap[root];
    }
};