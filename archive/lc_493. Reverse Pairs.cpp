// Binary Search, Divice and Conquer, Sort, Binary Indexed Tree, Segment Tree

class Solution {  // Binary Indexed Tree
public:
    static constexpr int MXN = 50000;
    int c[MXN+1];
    
    int reversePairs(vector<int>& nums) {
        set<int> s(begin(nums), end(nums));
        vector<int> sa;
        unordered_map<int, int> mp;
        int n = 0;
        for (auto &x : s) {
            sa.push_back(x);
            mp[x] = n++;
        }
        fill_n(c+1, n, 0);
        int ans = 0;
        for (int i=nums.size()-1; i>=0; --i) {
            auto p = upper_bound(begin(sa), end(sa), int(floor((nums[i]-1.0)/2)));
            int x = distance(begin(sa), p), tot = 0;
            while (x) tot += c[x], x -= x & -x;
            ans += tot;
            x = mp[nums[i]] + 1;
            while (x <= n) ++c[x], x += x & -x;
        }
        return ans;
    }
};

class Solution {  // Binary Indexed Tree 2
public:
    static constexpr int MXN = 50000;
    int c[MXN+1];
    
    int reversePairs(vector<int>& nums) {
        set<int> s(begin(nums), end(nums));
        vector<int> sa;
        unordered_map<int, int> mp;
        int n = 0;
        for (auto &x : s) {
            sa.push_back(x);
            mp[x] = n++;
        }
        fill_n(c+1, n, 0);
        int ans = 0;
        for (int i=0, l=nums.size(); i<l; ++i) {
            auto p = upper_bound(begin(sa), end(sa), 2LL*nums[i]);
            int x = distance(begin(sa), p) + 1, tot = 0;
            while (x <= n) tot += c[x], x += x & -x;
            ans += tot;
            x = mp[nums[i]] + 1;
            while (x) ++c[x], x -= x & -x;
        }
        return ans;
    }
};

class Solution {  // Merge Sort. Fastest
public:
    int merge2(vector<int> &A, int l, int r) {  // [l, r)
        if (r - l <= 1) return 0;
        int m = (l + r) / 2;
        int cnt = merge2(A, l, m) + merge2(A, m, r);
        for (int i=l, j=m; i<m && j<r; ++j) {
            while (i < m && A[i] <= 2LL * A[j]) ++i;
            cnt += m - i;
        }
        vector<int> tmp(begin(A) + l, begin(A) + m);
        for (int p=l, i=0, j=m; i<m-l;)
            A[p++] = j==r || tmp[i] <= A[j] ? tmp[i++] : A[j++];
        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        return merge2(nums, 0, nums.size());
    }
};