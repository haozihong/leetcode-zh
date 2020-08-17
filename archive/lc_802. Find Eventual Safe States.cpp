// Graph, DFS

class Solution {
public:
    void dfs(vector<int> &cur, vector<bool> &seen, vector<char> &safety, vector<vector<int>>& graph) {
        if (safety[cur.back()] == 1) return;
        if (seen[cur.back()] || safety[cur.back()] == 2) {
            for (auto &p : cur) safety[p] = 2;
            return;
        }
        seen[cur.back()] = true;
        for (const auto &j : graph[cur.back()]) {
            cur.push_back(j);
            dfs(cur, seen, safety, graph);
            cur.pop_back();
            if (safety[cur.back()]) break;
        }
        if (!safety[cur.back()]) safety[cur.back()] = 1;
        seen[cur.back()] = false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> cur;
        vector<char> safety(n, 0);  // 0: unknown, 1: safe, 2: unsafe
        vector<bool> seen(n, false);
        for (int i=0; i<n; ++i)
            if (!safety[i]) {
                cur.assign({i});
                dfs(cur, seen, safety, graph);
            }
        vector<int> ans;
        for (int i=0; i<n; ++i)
            if (safety[i] == 1) ans.push_back(i);
        return ans;
    }
};