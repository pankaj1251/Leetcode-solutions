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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>>mp;
        queue<pair<TreeNode*, pair<int, int>>>Q;
        Q.push({root, {0, 0}});

        while(!Q.empty()){
            TreeNode* temp = Q.front().first;
            int verticle_line = Q.front().second.first;
            int level = Q.front().second.second;
            Q.pop();
            mp[verticle_line][level].push_back(temp->val);

            if(temp->left){
                Q.push({temp->left, {verticle_line-1, level+1}});
            }
            
            if(temp->right){
                Q.push({temp->right, {verticle_line+1, level+1}});
            }
        }

        vector<vector<int>>ans;

        for(auto it: mp){
            vector<int>v;
            for(auto xx: it.second){
                sort(xx.second.begin(), xx.second.end());
                v.insert(v.end(), xx.second.begin(), xx.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};