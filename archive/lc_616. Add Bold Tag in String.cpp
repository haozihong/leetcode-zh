// Array, Hash Table, String, Trie, String Matching

class Trie {
public:
    unordered_map<char, Trie*> child;
    int l = 0;
    
    void add(const string& w) {
        auto p = this;
        for (char c : w)
            p = p->child[c] ? p->child[c] : p->child[c] = new Trie();
        p->l = w.length();
    }
    
    int search(const string& w, int i) {
        auto p = this;
        int mx = 0;
        for (int l=w.length(); i<l; ++i) {
            if ((p = p->child[w[i]]) == nullptr) return mx;
            mx = max(mx, p->l);
        }
        return mx;
    }
};

class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        Trie trie;
        for (string& w : words)
            trie.add(w);
        
        int n = s.length();
        vector<int> diff(n+1, 0);
        for (int i=0; i<n; ++i) {
            int l = trie.search(s, i);
            ++diff[i];
            --diff[i+l];
        }
        
        string res;
        int t = 0;
        for (int i=0; i<n; ++i) {
            if (t == 0 && diff[i]) res += "<b>";
            if (t && t + diff[i] == 0) res += "</b>";
            t += diff[i];
            res.push_back(s[i]);
        }
        if (t) res += "</b>";
        return res;
    }
};