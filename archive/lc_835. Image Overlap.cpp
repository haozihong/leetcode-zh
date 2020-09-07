// Array, Bit Manipulation

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        vector<int> An, Bn;
        for (int i=0, ta=0, tb=0; i<n; ++i, ta=0, tb=0) {
            for (int j=0; j<n; ++j) {
                ta = (ta<<1) + A[i][j];
                tb = (tb<<1) + B[i][j];
            }
            An.push_back(ta);
            Bn.push_back(tb);
        }
        int mx = 0;
        // translate A
        for (int di=0; di<n; ++di)
            for (int dj=0; dj<n; ++dj) {
                int t = 0;
                for (int i=di; i<n; ++i)
                    t += __builtin_popcount(An[i-di]>>dj & Bn[i]);
                if (t > mx) mx = t;
            }
        // translate B
        for (int di=0; di<n; ++di)
            for (int dj=0; dj<n; ++dj) {
                int t = 0;
                for (int i=di; i<n; ++i)
                    t += __builtin_popcount(Bn[i-di]>>dj & An[i]);
                if (t > mx) mx = t;
            }
        return mx;
    }
};