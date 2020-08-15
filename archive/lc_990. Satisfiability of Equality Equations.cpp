// Graph, Union Find

class UnionFind {
public:
    vector<int> id, sz;
    
    UnionFind(int n): id(n), sz(n, 1) {
        iota(id.begin(), id.end(), 0);
    }
    
    int find(int p) {
        return id[p] == p ? id[p] : id[p] = find(id[p]);
    }
    
    bool compare(int p, int q) { return find(p) == find(q); }
    
    void combine(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return;
        if (sz[i] < sz[j]) swap(i, j);
        id[j] = i;
        sz[i] += sz[j];
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& A) {
        UnionFind uf(26);
        for (auto &s : A)
            if (s[1] == '=')
                uf.combine(s[0]-97, s[3]-97);
        for (auto &s : A)
            if (s[1] == '!')
                if (uf.compare(s[0]-97, s[3]-97)) return false;
        return true;
    }
};