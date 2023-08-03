/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //iterative approach
    bool find_ans(TreeNode* root, TreeNode* head,vector<TreeNode*> &ans){
        if(root==NULL) return false;

        if(root->val==head->val) {
            ans.push_back(root);
            return true;
        }

        ans.push_back(root);

        if(find_ans(root->left,head,ans)) return true;
        if(find_ans(root->right,head,ans))return true;

        ans.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL)return root;
       
        vector<TreeNode*>left,right;

        find_ans(root, p, left);
        find_ans(root, q, right);

        int i=0, j=0, n=left.size(), m = right.size();
        // for(auto it: left)cout<<it->val<<" ";
        // cout<<endl;
        // for(auto it: right)cout<<it->val<<" ";
        while(i<n and j<m and left[i]==right[j]){
            i++;j++;
        }
        if(i==0)return NULL;
        return left[i-1];
    }
};