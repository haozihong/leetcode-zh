class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> e_out(n);
        vector<int> deg_in(n, 0);
        for (auto &c : prerequisites) {
            e_out[c[1]].push_back(c[0]);
            ++deg_in[c[0]];
        }
        vector<int> que;
        for (int i=0; i<n; ++i)
            if (!deg_in[i]) que.push_back(i);
        for (int i=0; i<que.size(); ++i)
            for (auto &q : e_out[que[i]]) {
                --deg_in[q];
                if (!deg_in[q]) que.push_back(q);
            }
        return que.size() == n ? que : vector<int>();
    }
};