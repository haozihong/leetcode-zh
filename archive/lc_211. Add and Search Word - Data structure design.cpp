// Trie, Design, 

class WordDictionary {
private:
    vector<vector<int>> trie{vector<int>(27)};
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(const string &word) {
        int p = 0;
        for (auto c : word) {
            c -= 97;
            if (trie[p][c] == 0) {
                trie[p][c] = trie.size();
                trie.emplace_back(27);
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