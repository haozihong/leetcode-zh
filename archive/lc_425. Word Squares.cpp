// String, Backtracking, Hash Table, Trie

class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<reference_wrapper<string>>> mp;
    vector<reference_wrapper<const string>> cur;

    void dfs() {
        if (cur.size() == cur[0].get().length()) {
            ans.emplace_back();
            copy(begin(cur), end(cur), back_inserter(ans.back()));
            return;
        }
        string pref = accumulate(begin(cur), end(cur), string(),
                                 [i=cur.size()](auto &x, auto &y) { return move(x) + y.get()[i]; });
        for (auto &w : mp[pref]) {
            cur.push_back(w);
            dfs();
            cur.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        mp.clear();
        for (auto &w : words)
            for (int i=1, l=w.length(); i<l; ++i)
                mp[w.substr(0, i)].push_back(w);
        ans.clear();
        for (const auto &w : words) {
            cur.assign({w});
            dfs();
        }
        return ans;
    }
};