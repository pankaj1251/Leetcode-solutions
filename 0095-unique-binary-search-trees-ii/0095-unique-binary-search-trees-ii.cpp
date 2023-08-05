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
    map<pair<int, int>, vector<TreeNode*>>umap;

    vector<TreeNode*> func(int start, int end){
        vector<TreeNode*>v;
        if(start > end){
            v.push_back(NULL);
            return v;
        }

        if(start==end){
            v.push_back(new TreeNode(start));
            return v;
        }

        if(umap.find({start, end}) != umap.end()){
            return umap[{start, end}];
        }

        for(int i=start; i<=end; i++){
            vector<TreeNode*>left = func(start, i-1); //left side of i
            vector<TreeNode*>right = func(i+1, end); //right side of i

            for(TreeNode* l: left){
                for(TreeNode* r: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    v.push_back(root);
                }
            }
        }

        return umap[{start, end}] = v;
    }

    vector<TreeNode*> generateTrees(int n) {
        return func(1, n);
    }
};