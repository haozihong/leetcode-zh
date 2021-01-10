// Binary Search, Binary Indexed Tree, Segment Tree, Ordered Map

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