// Binary Search, Divide and Conquer, Sort, Binary Indexed Tree, Segment Tree

using ll = long long;

class BIT {
public:
    size_t n;
    vector<int> c;
    
    BIT(const vector<int> &a): n(a.size()), c(a.size()+1, 0) {
        for (int i=0; i<n; ++i) {
            int j=i+1;
            while (j <= n) c[j] += a[i], j += j & -j;
        }
    }
    
    void update(int p, int d) {
        ++p;
        while (p <= n) c[p] += d, p += p & -p;
    }
    
    int pre_sum(int p) {
        ++p;
        int res = 0;
        while (p) res += c[p], p -= p & -p;
        return res;
    }
    
    int range_sum(int p, int q) {
        return p > q ? 0 : pre_sum(q) - (p ? pre_sum(p-1) : 0);
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<ll> ss(begin(nums), end(nums));
        unordered_map<ll, int> cnt{{ss[0], 1}};
        for (int i=1; i<n; ++i)
            ++cnt[ss[i] += ss[i-1]];
        set<ll> sss(begin(ss), end(ss));
        ss.assign(begin(sss), end(sss));
        vector<int> a(ss.size());
        unordered_map<ll, int> idx(ss.size());
        for (int i=0, l=ss.size(); i<l; ++i) {
            a[i] = cnt[ss[i]];
            idx[ss[i]] = i;
        }
        auto seg = BIT(a);
        
        auto ssb = begin(ss), sse = end(ss);
        auto p = lower_bound(ssb, sse, lower),
             q = upper_bound(ssb, sse, upper);
        int res = seg.range_sum(p - ssb, q - ssb - 1);
        ll s = 0;
        for (int i=0, l=ss.size(); i<n-1; ++i) {
            s += nums[i];
            seg.update(idx[s], -1);
            if (nums[i] < 0) {
                p = lower_bound(ssb, p, lower+s);
                q = upper_bound(ssb, q, upper+s);
            } else if (nums[i] > 0) {
                p = lower_bound(p, sse, lower+s);
                q = upper_bound(q, sse, upper+s);
            }
            res += seg.range_sum(p - ssb, q - ssb - 1);
        }
        return res;
    }
};