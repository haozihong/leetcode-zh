// Array

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> A(n, vector<int>(n, 0));
        int x = 0, y = -1, dx = 0, dy = 1;
        for (int i=1; i<=n*n; ++i) {
            x += dx; y += dy;
            if (x<0 or x>=n or y<0 or y>=n or A[x][y]!=0) {
                x-= dx; y -= dy;
                swap(dx, dy);
                dy = -dy;
                x += dx; y += dy;
            }
            A[x][y] = i;
        }
        return A;
    }
};