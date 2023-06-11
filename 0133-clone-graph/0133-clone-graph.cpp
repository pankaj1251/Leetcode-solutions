/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>umap;

    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;

        Node *ans = new Node(node->val, {});

        umap[node] = ans;

        queue<Node*>Q;
        Q.push(node);

        while(!Q.empty()){
            Node* temp = Q.front();
            Q.pop();

            for(auto it: temp->neighbors){
                if(umap.find(it) == umap.end()){
                    umap[it] = new Node(it->val, {});
                    Q.push(it);
                }
                umap[temp]->neighbors.push_back(umap[it]); 
            }
        }

        return ans;
    }
};