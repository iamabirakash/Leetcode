class TrieNode {
public:
    TrieNode* children[26];
    bool eof;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        eof = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (curr->children[i] == nullptr)
                curr->children[i] = new TrieNode();
            curr = curr->children[i];
        }
        curr->eof = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (curr->children[i] == nullptr)
                return false;
            curr = curr->children[i];
        }
        return curr->eof;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            int i = ch - 'a';
            if (curr->children[i] == nullptr)
                return false;

            curr = curr->children[i];
        }
        return true;
    }
};