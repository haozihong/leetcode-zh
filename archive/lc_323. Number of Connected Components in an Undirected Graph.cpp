//  Depth-first Seach, Breadth-first Search, Union Find, Graph

class Solution1 {  // dfs
public:
    void dfs(int p, vector<bool> &visi, vector<vector<int>> &g) {
        visi[p] = true;
        for (auto &q : g[p])
            if (!visi[q]) dfs(q, visi, g);
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        vector<bool> visi(n, false);
        int cnt = 0;
        for (int i=0; i<n; ++i)
            if (!visi[i]) dfs(i, visi, g), ++cnt;
        return cnt;
    }
};

class Solution2 {  // bfs
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        unordered_set<int> togo;
        generate_n(inserter(togo, begin(togo)), n, [i=0]() mutable { return i++; });
        deque<int> que;
        int cnt = 0;
        while (!togo.empty()) {
            que.assign({ *begin(togo) });
            togo.erase(begin(togo));
            ++cnt;
            while (!que.empty() && !togo.empty()) {
                for (auto &q : g[que.front()])
                    if (togo.count(q)) togo.erase(q), que.push_back(q);
                que.pop_front();
            }
        }
        return cnt;
    }
};

class UnionFind {
public:
    int cnt;
    vector<int> id, sz;
    
    UnionFind(int n): cnt(n), id(n), sz(n, 1) {
        iota(id.begin(), id.end(), 0);
    }
    
    int find(int p) {
        return id[p] == p ? id[p] : id[p] = find(id[p]);
    }
    
    bool compare(int p, int q) { return find(p) == find(q); }
    
    void combine(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return;
        --cnt;
        if (sz[i] < sz[j]) swap(i, j);
        id[j] = i;
        sz[i] += sz[j];
    }
    
    int count() { return cnt; }
};

class Solution {  // Union Find
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto &e : edges)
            uf.combine(e[0], e[1]);
        return uf.count();
    }
};