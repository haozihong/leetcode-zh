// Hash Table, Depth-first Search, Breadth-first Search

//  std::set 只需要比较, 不需要hash
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
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> island_st;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (grid[i][j] == 1)
                    dfs(i, j, island_st.size() + 2, grid), island_st.emplace_back(i, j);
        set<vector<ll>> islands;
        for (int id=2; id<island_st.size()+2; ++id) {
            int mnz = 63;
            auto [i, j] = island_st[id-2];
            vector<ll> island;
            for (; i<m; ++i) {
                ll row = 0;
                for (; j<n; ++j)
                    if (grid[i][j] == id) row |= 1LL<<j, mnz = min(mnz, j);
                if (row) island.push_back(row);
                else if (!island.empty()) break;
                j = 0;
            }
            for (auto &x : island) x >>= mnz;
            islands.insert(island);
        }
        return islands.size();
    }
};

// 用hash: bitset有hash特化
constexpr int MXN = 50;
using ll = long long;
using island_t = bitset<MXN*MXN>;

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
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> island_st;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (grid[i][j] == 1)
                    dfs(i, j, island_st.size() + 2, grid), island_st.emplace_back(i, j);

        unordered_set<island_t> islands;
        for (int id=2; id<island_st.size()+2; ++id) {
            auto [i, j] = island_st[id-2];
            island_t island;
            int mnz = 63, off = 0;
            for (; i<m; ++i) {
                bool flag = false;
                for (; j<n; ++j)
                    if (grid[i][j] == id)
                        flag = true, island.set(off+j), mnz = min(mnz, j);
                if (!flag) break;
                j = 0;
                off += MXN;
            }
            island >>= mnz;
            islands.insert(island);
        }
        return islands.size();
    }
};

// 自己实现的Trie. 并没什么必要
using ll = long long;

class Trie {
    int cnt = 0;
    vector<unordered_map<ll, int>> t;
    unordered_set<int> ends;
public:
    Trie(): t(1) {}
    
    void add(const vector<ll> &w) {
        int p = 0;
        for (auto x : w) {
            if (!t[p].count(x)) t[p][x] = t.size(), t.emplace_back();
            p = t[p][x];
        }
        if (!ends.count(p)) ++cnt;
        ends.insert(p);
    }
    
    int count() { return cnt; }
};

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
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> island_st;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (grid[i][j] == 1)
                    dfs(i, j, island_st.size() + 2, grid), island_st.emplace_back(i, j);
        
        Trie trie;
        for (int id=2; id<island_st.size()+2; ++id) {
            int mnz = 63;
            auto [i, j] = island_st[id-2];
            vector<ll> island;
            for (; i<m; ++i) {
                ll row = 0;
                for (; j<n; ++j)
                    if (grid[i][j] == id) row |= 1LL<<j, mnz = min(mnz, j);
                if (row) island.push_back(row);
                else if (!island.empty()) break;
                j = 0;
            }
            for (auto &x : island) x >>= mnz;
            trie.add(island);
        }
        return trie.count();
    }
};