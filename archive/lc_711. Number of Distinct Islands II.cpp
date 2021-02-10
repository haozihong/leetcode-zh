// Hash Table, Depth-first Search

using ll = long long;

class Solution {
public:
    void dfs(int x, int y, int id, vector<vector<int>> &grid) {
        if (grid[x][y] != 1) return;
        grid[x][y] = id;
        if (x > 0) dfs(x-1, y, id, grid);
        if (x + 1 < grid.size()) dfs(x+1, y, id, grid);
        if (y > 0) dfs(x, y-1, id, grid);
        if (y + 1 < grid[0].size()) dfs(x, y+1, id, grid);
    }
    
    void rotate(vector<ll> &A) {
        vector<ll> B;
        int n = A.size();
        for (int i=0; 1; ++i) {
            ll tmp = 0;
            for (int j=0; j<n; ++j)
                tmp |= (A[n-1-j] >> i & 1) << j;
            if (tmp) B.push_back(tmp);
            else break;
        }
        A.swap(B);
    }
    
    void reflect(vector<ll> &A) {
        reverse(begin(A), end(A));
    }
    
    void insert_all(set<vector<ll>> &S, vector<ll> &A) {
        S.insert(A);
        rotate(A); S.insert(A);
        rotate(A); S.insert(A);
        rotate(A); S.insert(A);
        reflect(A); S.insert(A);
        rotate(A); S.insert(A);
        rotate(A); S.insert(A);
        rotate(A); S.insert(A);
    }
    
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> island_st;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (grid[i][j] == 1)
                    dfs(i, j, island_st.size() + 2, grid), island_st.emplace_back(i, j);

        set<vector<ll>> islands;
        int cnt = 0;
        for (int id=2; id<island_st.size()+2; ++id) {
            int mnz = 63;
            vector<ll> island;
            auto [i, j] = island_st[id-2];
            for (; i<m; ++i) {
                ll row = 0;
                for (; j<n; ++j)
                    if (grid[i][j] == id) row |= 1LL<<j, mnz = min(mnz, j);
                if (row) island.push_back(row);
                else if (!island.empty()) break;
                j = 0;
            }
            for (auto &x : island) x >>= mnz;
            if (!islands.count(island)) insert_all(islands, island), ++cnt;
        }
        return cnt;
    }
};