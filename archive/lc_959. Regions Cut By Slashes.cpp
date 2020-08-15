// Graph, Union Find

class UnionFind {
public:
    int cnt;
    vector<int> id, sz;
    
    UnionFind(int n): cnt(n), id(n), sz(n, 1) {
        iota(begin(id), end(id), 0);
    }
    
    int find(int p) {
        return id[p] == p ? id[p] : id[p] = find(id[p]);
    }
    
    bool compare(int p, int q) { return find(p) == find(q); }
    
    void combine(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return ;
        if (sz[i] < sz[j]) swap(i, j);
        id[j] = i;
        sz[i] += sz[j];
        --cnt;
    }
    
    int count() { return cnt; }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UnionFind uf((2 * n + 1) * n + n);
        auto grid_pt = [&n](int i, int j) {
            return make_tuple((2*n+1)*i + j, (2*n+1)*i + n + j, (2*n+1)*i + n + j + 1, (2*n+1)*(i+1) + j);
        };
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                auto [pu, pl, pr, pd] = grid_pt(i, j);
                switch (grid[i][j]) {
                    case ' ':
                        uf.combine(pl, pr);
                    case '/':
                        uf.combine(pu, pl);
                        uf.combine(pd, pr);
                        break;
                    default:  // '\\'
                        uf.combine(pu, pr);
                        uf.combine(pd, pl);
                        break;
                }
            }
        return uf.count();
    }
};