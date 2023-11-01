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
    int maxcount=INT_MIN;
    int currcount=0;
    TreeNode* prev = NULL;
    vector<int>ans;

    void inorder(TreeNode* root, bool flag){
        if(!root)return;

        inorder(root->left, flag);

        if(prev != NULL and prev->val==root->val){
            currcount++;
        }
        else currcount=1;

        if(flag==false){
            maxcount = max(maxcount, currcount);
        }
        else{
            if(currcount == maxcount)ans.push_back(root->val);
        }

        prev=root;

        inorder(root->right, flag);
    }

    vector<int> findMode(TreeNode* root) {
        ans.clear();

        if(root==NULL)return ans;

        inorder(root, false);

        prev=NULL;
        currcount=0;

        inorder(root, true);

        return ans;
    }
};