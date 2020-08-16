// Array, Binary Search
// It's BINARY SEARCH!!! DP will get a TLE.

class Solution {
public:
    int maxDistance(vector<int>& A, int m) {
        sort(begin(A), end(A));
        int n = A.size(), l = 1, r = A.back() - A[0];
        while (l < r) {
            int mid = (l + r + 1) / 2, cnt = 1, p = 0;
            for (int i=1; i<n; ++i)
                if (A[i] - A[p] >= mid) {
                    p = i, ++cnt;
                    if (cnt >= m) break;
                }
            if (cnt >= m) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};