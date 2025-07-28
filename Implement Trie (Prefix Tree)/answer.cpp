class Trie {
public:
    Trie* child[26];
    bool isLeaf;
    Trie() {
        isLeaf = false;
        for(int  i=0;i<26;i++){
            child[i] = nullptr;
        }
    }
    void insert(string word) {
        Trie* root = this;
        for(char c : word){
            if(root->child[c-'a']==nullptr){
                Trie* newNode = new Trie();
                root->child[c-'a'] = newNode;
            }
            root = root->child[c-'a'];
        }
        root->isLeaf = true;
    }
    
    bool search(string word) {
        Trie* root = this;
        for(char c : word){
            if(root->child[c-'a']==nullptr) {
                return false;
            }
            root = root->child[c-'a'];
        }
        return root->isLeaf;
    }
    
    bool startsWith(string prefix) {
        Trie* root = this;
        for(char c : prefix){
            if(root->child[c-'a']==nullptr) {
                return false;
            }
            root = root->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
