// Tree, DFS, Union Find, Graph

// Done on 2020-08-11. Using the algorithm of leetcode official solution.

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> frm(n, -1);  // indegree of every vertex
        vector<vector<int>> cand;
        int ind2_v = -1;  // record the vertex with indegree of 2
        for (auto &e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            if (frm[v] != -1) {
                cand.push_back({frm[v]+1, v+1});
                cand.push_back(e);
            } else {
                frm[v] = u;
            }
        }
        if (cand.empty()) {  // all vertices have indegree of 1
            vector<bool> seen(n);
            int p = 0;
            while (!seen[p]) seen[p] = true, p = frm[p];
            fill(seen.begin(), seen.end(), false);
            while (!seen[p]) seen[p] = true, p = frm[p];
            for (auto it=edges.rbegin(); it!=edges.rend(); ++it)
                if (seen[(*it)[0]-1] && seen[(*it)[1]-1]) return *it;
            return {};
        } else {  // one vertex has an indegree of 2
            vector<bool> seen(n);
            int root = 0;
            while (!seen[root] && frm[root] != -1) seen[root] = true, root = frm[root];
            if (frm[root] != -1) return cand[0];
            vector<vector<int>> to(n);
            for (int i=0; i<n; ++i)
                if (frm[i] != -1) to[frm[i]].push_back(i);
            vector<int> st{root};
            fill(seen.begin(), seen.end(), false);
            int cnt = 0;
            while (!st.empty()) {
                auto p = st.back();
                st.pop_back();
                if (!seen[p]) {
                    seen[p] = true;
                    ++cnt;
                    move(to[p].begin(), to[p].end(), back_inserter(st));
                }
            }
            return cand[cnt==n];
        }
    }
};