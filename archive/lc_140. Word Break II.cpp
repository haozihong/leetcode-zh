class Solution {
public:
    struct TrieNode {
        int child[26];
        bool is_word = false;
        TrieNode() {
            fill_n(child, 26, 0);
        }
    };
    
    void add_word(const string &w, vector<TrieNode> &trie) {
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
    
    unordered_map<int, vector<vector<int>>> memo;

    vector<vector<int>> search_trie(int p, const string &s, const vector<TrieNode> &trie) {
        auto it = memo.find(p);
        if (it != memo.end()) return it->second;
        auto &res = memo[p];
        if (p == s.length()) {
            res.push_back(vector<int>());
            return res;
        }
        int q = 0;
        for (char c; p<s.length() && (c=s[p]); ++p) {
            c -= 97;
            if (trie[q].child[c] == 0) return res;
            q = trie[q].child[c];
            if (trie[q].is_word) {
                auto idxs = search_trie(p+1, s, trie);
                for (auto &idx : idxs) {
                    idx.insert(idx.begin(), {p+1});
                    res.push_back(move(idx));
                }
            }
        }
        return res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.length() == 0) return {};
        vector<TrieNode> trie(1);
        for (auto &w : wordDict)
            add_word(w, trie);
        memo.clear();
        auto idxs = search_trie(0, s, trie);
        vector<string> ans;
        for (auto &idx : idxs) {
            string sen(s.substr(0, idx[0]));
            for (int i=0, l=idx.size(); i<l-1; ++i)
                sen.append(" " + s.substr(idx[i], idx[i+1] - idx[i]));
            ans.push_back(move(sen));
        }
        return ans;
    }
};