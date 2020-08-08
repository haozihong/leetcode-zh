// Graph, Floyd

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> g;
        for (int i=0, l=values.size(); i<l; ++i) {
            auto &u = equations[i][0], &v = equations[i][1];
            g[u][v] = values[i];
            g[v][u] = 1 / values[i];
            g[u][u] = g[v][v] = 1;
        }
        for (auto ik=g.begin(); ik!=g.end(); ++ik) {
            const auto &k = ik->first;
            for (auto ii=g[k].begin(); ii!=g[k].end(); ++ii)
                for (auto ij=ii; ij!=g[k].end(); ++ij) {
                    const auto &i = ii->first, &j = ij->first;
                    if (g[i].count(j) == 0) {
                        g[i][j] = g[i][k] * g[k][j];
                        g[j][i] = 1 / g[i][j];
                    }
                }
        }
        vector<double> ans;
        for (auto &query : queries) {
            auto &u = query[0], &v = query[1];
            ans.push_back(g[u].count(v) ? g[u][v] : -1);
        }
        return ans;
    }
};