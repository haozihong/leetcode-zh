// Tree, DFS, Union Find, Graph

// Done on 2020-08-11. Not the same with solution on leetcode.
// The official solution is tricky and cool.

class UnionFind {
private:
    int n;
    vector<int> id, sz;
public:
    UnionFind(int n): n(n), id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }
    
    int find(int p) {
        if (id[p] != p) id[p] = find(id[p]);
        return id[p];
    }
    
    bool combine(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return false;
        if (sz[i] < sz[j]) swap(i, j);
        id[j] = i;
        sz[i] += sz[j];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        vector<bool> inv(n);  // indegree of every vertex
        int ind2_v = -1;  // record the vertex with indegree of 2
        vector<int> ce;  // record the last edge of a circle. could be the answer
        for (auto &e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            if (inv[v]) ind2_v = v;
            else inv[v] = true;
            if(!uf.combine(u, v)) ce = e;
            if (ind2_v != -1 && !ce.empty()) break;
        }
        if (ind2_v == -1) return ce;  // all vertices have indegree of 1
        // one vertex has an indegree of 2
        vector<int> us;  // vectices pointing to ind2_v
        uf = UnionFind(n);
        for (auto &e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            if (v == ind2_v) us.push_back(u);
            else uf.combine(u, v);
        }
        if (!uf.combine(us[0], ind2_v)) return {us[0]+1, ind2_v+1};
        else return {us[1]+1, ind2_v+1};
    }
};