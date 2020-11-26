// Divide and Conquer, Recursion, Sliding Window

// Divide and Conquer
class Solution {
public:
    array<int, 26> range_cnt(int l, int r, const vector<array<int, 26>> &cnts) {
        array<int, 26> res;
        copy(begin(cnts[r]), end(cnts[r]), begin(res));
        if (l > 0) 
            for (int i=0; i<26; ++i)
                res[i] -= cnts[l-1][i];
        return res;
    }
    
    int dfs(int l, int r, int k, const vector<array<int, 26>> &cnts, array<vector<int>, 26> &pos) {
        if (l > r) return 0;
        auto cnt = range_cnt(l, r, cnts);
        using viit = vector<int>::iterator;
        auto comp = [](const viit& it1, const viit& it2) { return *it1 > *it2; };
        priority_queue<viit, vector<viit>, decltype(comp)> que(comp);
        for (int i=0; i<26; ++i)
            if (cnt[i] > 0 && cnt[i] < k)
                que.push(lower_bound(begin(pos[i]), end(pos[i]), l));
        if (que.empty()) return r - l + 1;
        int p = l, mx = 0;
        while (!que.empty()) {
            auto it = que.top(); que.pop();
            if (*it - p > 0) mx = max(mx, dfs(p, *it-1, k, cnts, pos));
            p = *it + 1;
            if (*++it <= r) que.push(it);
        }
        if (p <= r) mx = max(mx, dfs(p, r, k, cnts, pos));
        return mx;
    }
    
    int longestSubstring(string &s, int k) {
        if (k == 1) return s.length();
        int n = s.length();
        vector<array<int, 26>> cnts(n);
        array<vector<int>, 26> pos;
        pos.fill(vector<int>());
        array<int, 26> cur; fill_n(begin(cur), 26, 0);
        for (int i=0; i<n; ++i) {
            ++cur[s[i]-'a'];
            copy(begin(cur), end(cur), begin(cnts[i]));
            pos[s[i]-'a'].push_back(i);
        }
        for (int i=0; i<26; ++i) pos[i].push_back(n+1);
        
        return dfs(0, n-1, k, cnts, pos);
    }
};

// Sliding Window
class Solution {
public:
    int longestSubstring(string &s, int k) {
        if (k == 1) return s.length();
        int unique_tot = unordered_set<char>(begin(s), end(s)).size();
        array<int, 26> cnt;
        int unique = 0, invalid = 0;
        auto add_char = [&](char c) {
            ++cnt[c -= 'a'];
            if (cnt[c] == 1) ++invalid, ++unique;
            else if (cnt[c] == k) --invalid;
        };
        auto del_char = [&](char c) {
            --cnt[c -= 'a'];
            if (cnt[c] == k-1) ++invalid;
            else if (cnt[c] == 0) --invalid, --unique;
        };
        int mx = 0;
        for (int unique_max=1, n=s.length(); unique_max<=unique_tot; ++unique_max) {
            fill_n(begin(cnt), 26, 0);
            unique = invalid = 0;
            int p = 0, q = 0;
            while (q < n) {
                while (q < n && unique <= unique_max) add_char(s[q++]);
                if (invalid == 1 && unique == unique_max + 1) mx = max(mx, q - p - 1);
                else if (invalid == 0) mx = max(mx, q - p);
                while (unique > unique_max) del_char(s[p++]);
            }
        }
        return mx;
    }
};