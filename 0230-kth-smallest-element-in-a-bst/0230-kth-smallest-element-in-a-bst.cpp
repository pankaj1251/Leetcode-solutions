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
void func(TreeNode* root, int &count, int k, int &ans){
    if(root==NULL)return;

    func(root->left, count, k, ans);

    count++;
    if(count==k){ans = root->val;return;}

    func(root->right, count, k, ans);
}
    int kthSmallest(TreeNode* root, int k) {
        int ans=0, count=0;
        func(root, count, k, ans);

        return ans;
    }
};