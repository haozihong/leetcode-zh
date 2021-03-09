// Graph
// 关键在于好好利用edge.length <= 10^5这点

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        int m = edges.size();
        vector<unordered_map<int, int>> g(n);
        vector<int> d(n, 0);
        for (auto &e : edges) {
            --e[0], --e[1];
            ++d[e[0]], ++d[e[1]];
            if (e[1] > e[0]) swap(e[0], e[1]);
            ++g[e[0]][e[1]];
        }
        vector<int> ds(d);
        sort(begin(ds), end(ds));
        
        vector<int> ans;
        for (auto &q : queries) {
            int t = 0;
            for (int i=0, j=n-1; i<n-1; ++i) {
                while (i < j && ds[i] + ds[j] > q) --j;
                t += n - 1 - max(j, i);
            }
            for (int u=0; u<n; ++u)
                for (auto &[v, w] : g[u])
                    if (d[u] + d[v] > q && d[u] + d[v] - w <= q) --t;
            ans.push_back(t);
        }
        return ans;
    }
};