// Two Pointers, Greedy

class Solution {
public:
    int numRescueBoats(vector<int>& A, int limit) {
        sort(begin(A), end(A));
        int ans = 0, p = 0, q = A.size() - 1;
        while (p < q) {
            if (A[p] + A[q] <= limit) ++p;
            --q;
            ++ans;
        }
        return ans + (p == q);
    }
};