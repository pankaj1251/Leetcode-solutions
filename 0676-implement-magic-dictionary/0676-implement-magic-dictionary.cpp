class Node{
public:
    Node* links[26];
    bool end=false;
};

class MagicDictionary {
public:
    Node* root;
    MagicDictionary() {
        root=new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(auto &ch: word){
            if(!node->links[ch-'a'])node->links[ch-'a']= new Node();
            node=node->links[ch-'a'];
        }
        node->end=true;
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &word: dictionary){
            insert(word);
        }
    }
    
    bool check(string &word){
        Node* node = root;
        for(auto &ch: word){
            if(!node->links[ch-'a'])return false;
            node=node->links[ch-'a'];
        }
        return node->end;
    }

    bool search(string sword) {
        int n=sword.size();
        string word=sword;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                if('a'+j==sword[i]) continue;
                word[i]='a'+j;
                if(check(word)) return true;
            }
            word[i]=sword[i];
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */