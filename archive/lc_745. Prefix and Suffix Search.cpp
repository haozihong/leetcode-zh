class WordFilter {
private:
    struct TrieNode {
        array<TrieNode *, 27> child;
        int weight = -1;
        TrieNode() { child.fill(nullptr); }
    } root;
    
    void add_suffix(const string &w, int weight) {
        for (int st=0, l=w.length(); st<=l; ++st) {
            auto p = &root;
            for (int i=st; i<l; ++i) {
                char c = w[i] - 97;
                p = p->child[c] ?: (p->child[c] = new TrieNode());
            }
            p = p->child[26] ?: (p->child[26] = new TrieNode());
            p->weight = weight;
            for (auto c : w) {
                c -= 97;
                p = p->child[c] ?: (p->child[c] = new TrieNode());
                p->weight = weight;
            }
        }
    }
    
public:
    WordFilter(vector<string>& words) {
        for (int i=0, l=words.size(); i<l; ++i)
            add_suffix(words[i], i);
    }
    
    int f(const string &prefix, const string &suffix) {
        string w = suffix + char(97+26) + prefix;
        auto p = &root;
        for (auto &c : w) {
            if (!(p = p->child[c-97])) return -1;
        }
        return p->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */