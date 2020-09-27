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


// 2020-09-27  this is faster. beats 100%
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int node_cnt = 0;
        unordered_map<string, int> mpi;
        for (auto &e : equations)
            for (auto &v : e)
                if (!mpi.count(v)) mpi[v] = node_cnt++;
        vector<vector<double>> g(node_cnt, vector<double>(node_cnt, -1));
        for (int i=0; i<node_cnt; ++i) g[i][i] = 1;
        for (int i=0, p, q, l=values.size(); i<l; ++i) {
            p = mpi[equations[i][0]]; q = mpi[equations[i][1]];
            g[p][q] = values[i];
            g[q][p] = values[i] != 0 ? 1 / values[i] : -1;
        }
        for (int k=0; k<node_cnt; ++k)
            for (int i=0; i<node_cnt; ++i)
                for (int j=0; j<node_cnt; ++j)
                    if (g[i][j] == -1 && g[i][k] != -1 && g[k][j] != -1)
                        g[i][j] = g[i][k] * g[k][j];
        vector<double> ans;
        for (auto &q : queries)
            ans.push_back(mpi.count(q[0]) && mpi.count(q[1]) ? g[mpi[q[0]]][mpi[q[1]]] : -1);
        return ans;
    }
};