// Segment Tree, Ordered Map

class SegTree {  // range maximum
public:
    int sz;
    vector<int> d, b;
    
    SegTree(int n): sz(1<<int(ceil(log2(n))+1)), d(sz+1, 0), b(sz+1, 0) {}
    
    void update(int l, int r, int v, int s, int t, int p) {  // update maximum
        if (l <= s && t <= r) {
            if (v > d[p]) d[p] = b[p] = v;
            return;
        }
        int m = s + (t - s) / 2;
        if (s != t && b[p] == d[p]) {
            d[p*2] = b[p*2] = d[p];
            d[p*2+1] = b[p*2+1] = d[p];
            b[p] = 0;
        }
        if (l <= m) update(l, r, v, s, m, p*2);
        if (m < r) update(l, r, v, m+1, t, p*2+1);
        d[p] = max(d[p*2], d[p*2+1]);
    }
    
    int range_max(int l, int r, int s, int t, int p) {
        if (l <= s && t <= r)
            return d[p];
        int m = s + (t - s) / 2;
        if (s != t && b[p] == d[p]) {
            d[p*2] = b[p*2] = d[p];
            d[p*2+1] = b[p*2+1] = d[p];
            b[p] = 0;
        }
        int res = 0;
        if (l <= m) res = range_max(l, r, s, m, p*2);
        if (m < r) res = max(res, range_max(l, r, m+1, t, p*2+1));
        return res;
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& pos) {
        vector<int> ns;
        for (auto &sq : pos) ns.push_back(sq[0]), ns.push_back(sq[0] + sq[1] - 1);
        set<int> nss(begin(ns), end(ns));
        unordered_map<int, int> mp;
        int n = 0;
        for (auto &x : nss) mp[x] = ++n;
        SegTree seg(n);
        vector<int> ans;
        for (auto &sq : pos) {
            int l = mp[sq[0]], r = mp[sq[0]+sq[1]-1];
            seg.update(l, r, seg.range_max(l, r, 1, n, 1)+sq[1], 1, n, 1);
            ans.push_back(seg.range_max(1, n, 1, n, 1));
        }
        return ans;
    }
};