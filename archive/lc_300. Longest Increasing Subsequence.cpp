// Binary Search, Dynamic Programming

class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        vector<int> d{A[0]};
        for (int i=1, n=A.size(); i<n; ++i) {
            if (A[i] > d.back())
                d.push_back(A[i]);
            else
                *lower_bound(begin(d), end(d), A[i]) = A[i];
        }
        return d.size();
    }
};