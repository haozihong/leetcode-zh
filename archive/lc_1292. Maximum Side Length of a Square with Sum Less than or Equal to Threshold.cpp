// Binary Search, Array

class Solution1 {  // Binary Search for global side length
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        for (int j=1; j<n; ++j) mat[0][j] += mat[0][j-1];
        for (int i=1; i<m; ++i)
            for (int j=0, t=0; j<n; ++j)
                mat[i][j] = mat[i-1][j] + (t += mat[i][j]);
        int l = 0, r = min(m, n) + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            bool flag = false;
            for (int i=mid-1; i<m && !flag; ++i)
                for (int j=mid-1; j<n; ++j) {
                    int t = mat[i][j];
                    if (i-mid >= 0) t -= mat[i-mid][j];
                    if (j-mid >= 0) t -= mat[i][j-mid];
                    if (i-mid >= 0 && j-mid >= 0) t += mat[i-mid][j-mid];
                    if (t <= threshold) { flag = true; break; }
                }
            if (flag) l = mid;
            else r = mid;
        }
        return l;
    }
};

class Solution {  // Binary search the side length for each cell
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        for (int j=1; j<n; ++j) mat[0][j] += mat[0][j-1];
        for (int i=1; i<m; ++i)
            for (int j=0, t=0; j<n; ++j)
                mat[i][j] = mat[i-1][j] + (t += mat[i][j]);
        vector<int> row(n+1, 0);
        int ans = 0;
        for (int i=m, prev=0; --i; prev=0) {
            for (int j=n; --j; ) {
                int l = max({0, prev-1, row[j]-1, row[j+1]-1}), r = min(i+1, j+1) + 1;
                for (int mid, t; l + 1 < r; ) {
                    mid = (l + r) / 2;
                    t = mat[i][j];
                    if (i-mid >= 0) t -= mat[i-mid][j];
                    if (j-mid >= 0) t -= mat[i][j-mid];
                    if (i-mid >= 0 && j-mid >= 0) t += mat[i-mid][j-mid];
                    if (t <= threshold) l = mid;
                    else r = mid;
                }
                if (l > ans) ans = l;
                row[j+1] = prev; prev = l;
            }
            row[0] = prev;
        }
        return ans;
    }
};