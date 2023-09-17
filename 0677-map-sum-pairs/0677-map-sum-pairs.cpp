class Node{
    public:
    Node* links[26];
    int sum=0;
};

class MapSum {
public:
    Node* root;
    unordered_map<string, int>mp;
    MapSum() {
        root = new Node();
    }
    
    void insert(string word, int val) {
        Node* node=root;
        int diff = val-mp[word];

        for(int i=0; i<word.size(); i++){
            if(!node->links[word[i]-'a'])node->links[word[i]-'a']=new Node();
            node=node->links[word[i]-'a'];
            node->sum += diff;
        }
        mp[word]=val;
    }
    
    int sum(string prefix) {
        int ans=0;
        Node* node=root;
        for(int i=0; i<prefix.size(); i++){
            if(!node->links[prefix[i]-'a'])return 0;
            node=node->links[prefix[i]-'a'];
            ans = node->sum;
        }   

        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */