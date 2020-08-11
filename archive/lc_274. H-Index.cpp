//Hash Table, Sort

class Solution1 {
public:
    int hIndex(vector<int>& A) {
        sort(A.begin(), A.end(), greater<int>());
        int i = 0;
        while (i < A.size() && A[i] >= i + 1) ++i;
        return i;
    }
};

class Solution {
public:
    int hIndex(vector<int>& A) {
        if (A.empty()) return 0;
        int mxh = min(*max_element(A.begin(), A.end()), int(A.size()));
        vector<int> cnt(mxh+1);
        for (auto &i : A)
            ++cnt[min(i, mxh)];
        if (cnt[mxh] >= mxh) return mxh;
        for (int i=mxh-1; i; --i)
            if ((cnt[i] += cnt[i+1]) >= i) return i;
        return 0;
    }
};