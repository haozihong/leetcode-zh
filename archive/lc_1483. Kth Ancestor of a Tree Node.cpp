// DP, Binary Lifting, 倍增

const int K = 16;
array<array<int, K>, 50000> anc;

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        for (int i=0; i<n; ++i)
            anc[i][0] = parent[i];
        for (int k=1; k<K; ++k)
            for (int i=0; i<n; ++i)
                anc[i][k] = anc[i][k-1] != -1 ? anc[anc[i][k-1]][k-1] : -1;
    }
    
    int getKthAncestor(int node, int k) {
        for (int i=0; i<K && node!=-1; ++i)
            if (k & 1<<i) node = anc[node][i];
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */