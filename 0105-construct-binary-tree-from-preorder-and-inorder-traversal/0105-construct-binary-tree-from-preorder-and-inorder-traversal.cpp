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
    TreeNode* func(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end, unordered_map<int, int>&umap)  
    {
        if(in_start > in_end || pre_start > pre_end)return NULL;

        TreeNode* root = new TreeNode(preorder[pre_start]);

        int in_root = umap[root->val];

        root->left = func(preorder, pre_start+1, pre_start + in_root - in_start, inorder, in_start, in_root-1, umap);
        root->right = func(preorder, pre_start + in_root - in_start + 1, pre_end, inorder, in_root+1, in_end, umap);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int>umap;

        for(int i=0; i<n; i++){
            umap[inorder[i]]=i;
        }

        TreeNode* root = func(preorder, 0, n-1, inorder, 0, n-1, umap);
        return root;
    }
};