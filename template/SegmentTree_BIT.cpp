/* 
 * https://oi-wiki.org/ds/fenwick/
 */

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<typename T>
class BIT {
public:
    size_t n;
    vector<T> t;

    inline static T lowbit(T x) { return x & -x; }

    BIT(size_t n): n(n), t(n+1, 0) {}

    BIT(const vector<T>& a): n(a.size()), t(n+1, 0) {
        for (size_t i=1, j; i<=n; ++i) {
            t[i] += a[i-1];
            if (j = i + lowbit(i) <= n) t[j] += t[i];
        }
    }

    void add(size_t x, T v=1) {
        while (x <= n) t[x] += v, x += lowbit(x);
    }

    // sum of [1..r], 1-based indexing
    T pref_sum(size_t r) {
        int res = 0;
        while (r > 0) res += t[r], r -= lowbit(r);
        return res;
    }

    // sum of [l..r], 1-based indexing
    T range_sum(size_t l, size_t r) {
        return l > 1 ? pref_sum(r) - pref_sum(l-1) : pref_sum(r);
    }

    // value of a[x], 1-based indexing
    T get_val(size_t x) { return range_sum(x-1, x); }
};

struct SegTreeMax {  // range maximum. LC_699. Falling Squares
    int s0, t0, n, sz;
    vector<int> d;
    vector<bool> b; // 0: passed down; 1: lazy tag
    
    SegTreeMax(int s, int t)
        : s0(s), t0(t), n(t0 - s0 + 1),
          sz(1<<(int(ceil(log2(n)))+1)), d(sz, 0), b(sz, false) {}
    
    void update(int l, int r, int c) { update(l, r, c, s0, t0, 1); }
    
    void update(int l, int r, int v, int s, int t, int p) {
        if (l <= s && t <= r && v >= d[p]) {
            d[p] = v;
            b[p] = true;
            return;
        }
        if (s == t) return;
        int m = (s + t) / 2;
        if (b[p]) {
            d[p*2] = d[p*2+1] = d[p];
            b[p*2] = b[p*2+1] = true;
            b[p] = false;
        }
        if (l <= m) update(l, r, v, s, m, p*2);
        if (m < r) update(l, r, v, m+1, t, p*2+1);
        d[p] = max(d[p*2], d[p*2+1]);
    }
    
    int query(int l, int r) { return query(l, r, s0, t0, 1); }
    
    int query(int l, int r, int s, int t, int p) {
        if (l <= s && t <= r) return d[p];
        int m = (s + t) / 2;
        if (b[p]) {
            d[p*2] = d[p*2+1] = d[p];
            b[p*2] = b[p*2+1] = true;
            b[p] = false;
        }
        int res = INT_MIN;
        if (l <= m) res = max(res, query(l, r, s, m, p*2));
        if (m < r) res = max(res, query(l, r, m+1, t, p*2+1));
        return res;
    }
};

struct SegTreeSet {  // range set. LC_2158. Amount of New Area Painted Each Day
    int s0, t0, n, sz;
    vector<int> d, b;
    vector<bool> v; // 0: passed down; 1: lazy tag
    
    SegTreeSet(int s, int t)
        : s0(s), t0(t), n(t0 - s0 + 1),
          sz(1<<(int(ceil(log2(n)))+1)), d(sz, 0), b(sz, 0), v(sz, false) {}
    
    void update(int l, int r, int c) { update(l, r, c, s0, t0, 1); }
    
    void update(int l, int r, int c, int s, int t, int p) {
        if (s > t) s = s0, t = t0;
        if (l <= s && t <= r) {
            d[p] = (t - s + 1) * c, b[p] = c, v[p] = 1;
            return;
        }
        int m = s + ((t - s) >> 1);
        if (v[p]) {
            d[p*2] = b[p] * (m - s + 1), d[p*2+1] = b[p] * (t - m);
            b[p*2] = b[p*2+1] = b[p];
            v[p*2] = v[p*2+1] = 1;
            v[p] = 0;
        }
        if (l <= m) update(l, r, c, s, m, p*2);
        if (r > m) update(l, r, c, m + 1, t, p*2+1);
        d[p] = d[p*2] + d[p*2+1];
    }
    
    int query(int l, int r) { return query(l, r, s0, t0, 1); }

    int query(int l, int r, int s, int t, int p) {
        if (l <= s && t <= r) return d[p];
        int m = s + ((t - s) >> 1);
        if (v[p]) {
            d[p*2] = b[p] * (m - s + 1), d[p*2+1] = b[p] * (t - m);
            b[p*2] = b[p*2+1] = b[p];
            v[p*2] = v[p*2+1] = 1;
            v[p] = 0;
        }
        int sum = 0;
        if (l <= m) sum = query(l, r, s, m, p*2);
        if (r > m) sum += query(l, r, m + 1, t, p*2+1);
        return sum;
    }
};

class Solution {
public:
    int MOD = 1e9 + 7;
    int createSortedArray(vector<int>& A) {
        int mx = *max_element(begin(A), end(A));
        BIT<int> b(mx);
        int ans = 0;
        for (auto &x : A) {
            ans = (ans + min(b.pref_sum(x-1), b.range_sum(x+1, mx))) % MOD;
            b.add(x);
        }
        return ans;
    }
};

int main() {
    // vector<int> in0{1,5,6,2};
    // vector<int> in0{1,2,3,6,5,4};
    vector<int> in0{1,3,3,3,2,4,2,1,2};

    auto ou = Solution().createSortedArray(in0);
    cout << ou << endl;
}