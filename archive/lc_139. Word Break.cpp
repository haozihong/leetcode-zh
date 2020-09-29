// Trie, DP

class Solution {
public:
    struct TrieNode {
        bool is_word = false;
        int child[26];
        TrieNode() { fill_n(child, 26, 0); }
    };
    
    vector<TrieNode> trie;
    unordered_map<int, bool> memo;

    void add_word(const string &w) {
        int p = 0;
        for (auto c : w) {
            c -= 97;
            if (trie[p].child[c] == 0) {
                trie[p].child[c] = trie.size();
                trie.emplace_back();
            }
            p = trie[p].child[c];
        }
        trie[p].is_word = true;
    }
    
    bool match_sentence(const string& s, int pos=0) {
        if (memo.count(pos)) return memo[pos];
        if (pos >= s.length()) return memo[pos] = true;
        int p = 0;
        for (int i=pos, l=s.length(); i<l; ++i) {
            char c = s[i] - 97;
            if (trie[p].child[c] == 0) return memo[pos] = false;
            p = trie[p].child[c];
            if (trie[p].is_word && (i + 1 == l || match_sentence(s, i + 1)))
                return memo[pos] = true;
        }
        return memo[pos] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        trie.assign(1, TrieNode());
        for (auto &w : wordDict) add_word(w);
        memo.clear();
        return match_sentence(s);
    }
};