// Graph, Union Find, 
// Note: Hashing a string takes O(string.length) time.

class UnionFind {
public:
    int cnt;
    vector<int> id;
    
    UnionFind(int n): cnt(n), id(n) { iota(begin(id), end(id), 0); }
    
    int find(int p) { return id[p] == p ? p : id[p] = find(id[p]); }
    
    void combine(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return;
        id[j] = i;
        --cnt;
    }
    
    int count() { return cnt; }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        unordered_set<string> ss(begin(A), end(A));
        A.assign(begin(ss), end(ss));
        int n = ss.size(), lng = A[0].length();
        UnionFind uf(n);
        if (n < lng * lng) {
            for (int i=0; i<n-1; ++i)
                for (int j=i+1; j<n; ++j) {
                    int cnt = 0;
                    for (int k=0; k<lng; ++k)
                        if ((cnt += A[i][k] != A[j][k]) > 2) break;
                    if (cnt == 2 || cnt == 0) uf.combine(i, j);
                }
        } else {
            unordered_map<string, int> d;
            for (int i=0; i<n; ++i) d[A[i]] = i;
            for (int i=0; i<n; ++i) {
                string w{A[i]};
                for (int j=0; j<lng-1; ++j)
                    for(int k=j+1; k<lng; ++k) {
                        if (w[j] == w[k]) continue;
                        swap(w[j], w[k]);
                        if (d.count(w)) uf.combine(i, d[w]);
                        swap(w[j], w[k]);
                    }
            }
        }
        return uf.count();
    }
};