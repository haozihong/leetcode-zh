// Array, Binary Search, Divide and Conquer, Hard, Complex

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() < B.size()) swap(A, B);
        int m = A.size(), n = B.size();
        if (n == 0) return m % 2 ? A[m/2] : (A[m/2-1] + A[m/2]) / 2.0;
        int mi = (m + n - 1) / 2;
        int l = 0, r = mi;
        while (l < r) {
            int p = (l + r + 1) / 2;
            int q = mi - p;
            if (q >= n || A[p] <= B[q]) {
                if (q > n || q > 0 && A[p] < B[q-1]) {
                    l = p + 1;
                } else {
                    l = p; break;
                } 
            } else {
                if (p > 0 && B[q] < A[p-1]) {
                    r = p - 1;
                } else {
                    l = p; break;
                }                 
            }
        }
        vector<int> tmp{A[l]};
        if (l + 1 < m) tmp.push_back(A[l+1]);
        if (mi+1-l < n) tmp.push_back(B[mi+1-l]);
        if (mi-l < n) tmp.push_back(B[mi-l]);
        if ((m + n) % 2) {
            return *min_element(begin(tmp), end(tmp));
        }else {
            sort(begin(tmp), end(tmp));
            return (tmp[0] + tmp[1]) / 2.0;
        }
    }
};