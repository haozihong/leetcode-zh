// Trie, Design, 

// 2020-08-05
class WordDictionary {
private:
    vector<array<int, 27>> trie{1};
    
public:
    /** Initialize your data structure here. */
    WordDictionary() { trie[0].fill(0); }
    
    /** Adds a word into the data structure. */
    void addWord(const string &word) {
        int p = 0;
        for (auto c : word) {
            c -= 97;
            if (trie[p][c] == 0) {
                trie[p][c] = trie.size();
                trie.emplace_back();
                trie.back().fill(0);
            }
            p = trie[p][c];
        }
        trie[p].back() = 1;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string &word, int i=0, int p=0) {
        for (; i<word.length(); ++i) {
            if (word[i] != '.') {
                char c = word[i] - 97;
                if ((p = trie[p][c]) == 0) return false;
            } else {
                for (int j=0; j<26; ++j)
                    if (trie[p][j] && search(word, i+1, trie[p][j])) return true;
                return false;
            }
        }
        return trie[p].back();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


// 2019-12-07 (edit on 2020-08-05)
class WordDictionary {
private:
    struct TrieNode {
        bool isWord = false;
        array<TrieNode *, 26> child;
        TrieNode(): { child.fill(nullptr); }
    } root;
    
public:
    /** Initialize your data structure here. */
    WordDictionary(): root() {}
    
    /** Adds a word into the data structure. */
    void addWord(const string &word) {
        TrieNode *p = &root;
        for (auto c : word) {
            c -= 97;
            if (!p->child[c]) p->child[c] = new TrieNode();
            p = p->child[c];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string &word, int i = 0, TrieNode *p = nullptr) {
        if (!p) p = &root;
        for (; i < word.length() && word[i] != '.'; ++i) {
            char c = word[i] - 97;
            if (!p->child[c]) return false;
            p = p->child[c];
        }
        if (i == word.size()) return p->isWord;
        // then word[i] is '.'
        for (int k=0; k<26; ++k)
            if (p->child[k] && search(word, i+1, p->child[k])) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */