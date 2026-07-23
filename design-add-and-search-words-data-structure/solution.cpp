class TrieNode {
public:
    TrieNode* children[26];
    bool eow;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        eow = false;
    }
};

class WordDictionary {
    TrieNode* root;

    bool dfs(string &word, int idx, TrieNode* node) {
        if (idx == word.size())
            return node->eow;

        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] &&
                    dfs(word, idx + 1, node->children[i]))
                    return true;
            }
            return false;
        }

        int i = word[idx] - 'a';

        if (!node->children[i])
            return false;

        return dfs(word, idx + 1, node->children[i]);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int i = ch - 'a';

            if (!curr->children[i])
                curr->children[i] = new TrieNode();

            curr = curr->children[i];
        }

        curr->eow = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};