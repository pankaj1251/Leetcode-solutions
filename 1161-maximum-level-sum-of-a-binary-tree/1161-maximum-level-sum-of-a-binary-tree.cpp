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
    int maxLevelSum(TreeNode* root) {
        int maxsum=INT_MIN, ans=1;
        int level=1;
        queue<TreeNode*>Q;
        Q.push(root);

        while(!Q.empty()){
            int sum=0;
            int sz = Q.size();
            while(sz--){
                TreeNode* node = Q.front();
                Q.pop();
                sum += node->val;
                if(node->left)Q.push(node->left);
                if(node->right)Q.push(node->right);
            }

            if(maxsum<sum){
                maxsum=sum;
                ans = level;
            }
            level++;
        }

        return ans;
    }
};