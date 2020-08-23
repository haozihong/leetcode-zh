// Trie
// Make sure passing by reference

class Trie {
public:
    struct TrieNode {
        bool is_word = false;
        array<TrieNode *, 26> child;
        TrieNode() { fill(begin(child), end(child), nullptr); }
    } root;

    void radd(string &w) {
        auto p = &root;
        for (int i=w.length(); i--;) {
            char c = w[i] - 'a';
            if (!p->child[c]) p->child[c] = new TrieNode();
            p = p->child[c];
        }
        p->is_word = true;
    }

    bool rsearch2(string &w) {
        auto p = &root;
        for (int i=w.length(); i--;) {
            char c = w[i] - 'a';
            if (!(p = p->child[c])) return false;
            if (p->is_word) return true;
        }
        return false;
    }
};

class StreamChecker {
public:
    Trie trie;
    string qu;
    
    StreamChecker(vector<string>& words) {
        for (auto &s : words) trie.radd(s);
    }
    
    bool query(char letter) {
        qu.push_back(letter);
        return trie.rsearch2(qu);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */ 