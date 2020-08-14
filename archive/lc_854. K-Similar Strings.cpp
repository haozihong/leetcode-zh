// Graph, DFS, BFS

class Solution {  // DFS
public:
    int dfs(int i, string &A, const string &B) {
        if (i >= A.size()) return 0;
        if (A[i] == B[i]) return dfs(i+1, A, B);
        vector<int> ks;
        for (int j=i+1, l=A.length(); j<l; ++j)
            if (B[i] == A[j]) {
                if (A[i] == B[j]) {
                    ks.assign({j});
                    break;
                }
                ks.push_back(j);
            }
        int mn = A.length();
        for (auto &k : ks) {
            swap(A[i], A[k]);
            mn = min(mn, dfs(i+1, A, B) + 1);
            swap(A[i], A[k]);
        }
        return mn;
    }
    
    int kSimilarity(string A, string B) {
        return dfs(0, A, B);
    }
};

class Solution2 {  // BFS, slower than DFS
public:
    int kSimilarity(string A, string B) {
        int l = A.length();
        deque<tuple<string, char, char>> que;
        que.emplace_back(B, 0, 0);
        while (!que.empty()) {
            auto &[s, i, cost] = que.front();
            while (i < l && s[i] == A[i]) ++i;
            if (i == l) return cost;
            for (auto j=i+1; j<l; ++j)
                if (s[j] == A[i]) {
                    string tmp{s};
                    swap(tmp[i], tmp[j]);
                    que.emplace_back(move(tmp), i + 1, cost + 1);
                }
            que.pop_front();
        }
        return l-1;
    }
};