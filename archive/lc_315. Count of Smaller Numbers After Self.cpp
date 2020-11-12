// Binary Search, Divide and Conquer, Sort, Binary Indexed Tree, Segment Tree

class Solution {  // Binary Indexed Tree
public:
    static constexpr int MXN = 20010;
    int c[MXN];
    
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() <= 1) return vector<int>(nums.size(), 0);
        auto pmnmx = minmax_element(begin(nums), end(nums));
        int off = -*pmnmx.first + 1, n = *pmnmx.second - *pmnmx.first + 1;
        fill_n(c + 1, n, 0);
        vector<int> ans;
        for (int i=nums.size()-1; i>=0; --i) {
            int x = nums[i] + off - 1, s = 0;
            while (x) s += c[x], x -= x & -x;
            ans.push_back(s);
            x = nums[i] + off;
            while (x <= n) ++c[x], x += x & -x;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};

using ii = pair<int,int>;
class Solution {  // Divide and Conquer, Merge Sort
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> cnt(nums.size());
        vector<ii> zips(nums.size());
        generate(zips.begin(), zips.end(),
                 [i=0, it=nums.begin()]() mutable { return make_pair(*(it++), i++); });
        merge_sort2(zips, 0, nums.size(), cnt);
        return cnt;
    }
    
    void merge_sort2(vector<ii>& A, int l, int r, vector<int>& cnt) {
        if (l + 1 >= r) return;
        int m = (l + r) / 2;
        merge_sort2(A, l, m, cnt);
        merge_sort2(A, m, r, cnt);
        vector<ii> tmp(A.begin() + l, A.begin() + m);
        int i = l, j = m, p = l;
        while (i < m && j < r) {
            if (tmp[i-l].first <= A[j].first) {
                A[p++] = tmp[i-l];
                cnt[tmp[i++-l].second] += j - m;
            } else {
                A[p++] = A[j++];
            }
        }
        for (; i < m; ++i) {
            A[p++] = tmp[i-l];
            cnt[tmp[i-l].second] += j - m;
        }
    }
};