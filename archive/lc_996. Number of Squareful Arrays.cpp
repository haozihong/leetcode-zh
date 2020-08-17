// Graph, Math, Backtracking, DFS, DP

class Solution1 {  // DFS
public:
    inline bool is_sq(int x) {
        int t = int(sqrt(x));
        return t * t == x;
    }
    
    int dfs(int cur, int rst, unordered_map<int, int> &cnt, unordered_map<int, vector<int>> &tb, const int &n) {
        if (rst == 0) return 1;
        --cnt[cur];
        int res = 0;
        for (auto &j : tb[cur])
            if (cnt[j]) {
                res += dfs(j, rst-1, cnt, tb, n);
            }
        ++cnt[cur];
        return res;
    }
    
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> cnt;
        for (int i=0; i<n; ++i) ++cnt[A[i]];
        unordered_map<int, vector<int>> tb(n);
        for (auto &[x, c] : cnt)
            for (auto &[y, _] : cnt)
                if (is_sq(x + y) && (x != y || c > 1))
                    tb[x].push_back(y);
            
        int ans = 0;
        for (auto &[x, _] : cnt) {
            ans += dfs(x, n-1, cnt, tb, n);
        }
        return ans;
    }
};

class Solution {  // DP. So slow
public:
    inline bool is_sq(int x) {
        int t = int(sqrt(x));
        return t * t == x;
    }
    
    vector<vector<int>> dp;  // dp[state][last]
    int f(int state, int p, const vector<int> &A, const vector<vector<int>> &tb) {
        if (dp[state][p] != -1) return dp[state][p];
        dp[state][p] = 0;
        int s0 = state - (1<<p);
        for (auto &i : tb[p])
            if (s0 & 1<<i) dp[state][p] += f(s0, i, A, tb);
        return dp[state][p];
    }
    
    int numSquarefulPerms(vector<int>& A) {
        if (A.size() <= 1) return 0;
        int n = A.size();
        dp = vector<vector<int>>(1<<n, vector<int>(n, -1));
        vector<vector<int>> tb(n);
        for (int i=0; i<n-1; ++i)
            for (int j=i+1; j<n; ++j) {
                int t = 1<<i | 1<<j;
                if (is_sq(A[i] + A[j])) {
                    tb[i].push_back(j);
                    tb[j].push_back(i);
                    dp[t][i] = dp[t][j] = 1;
                } else {
                    dp[t][i] = dp[t][j] = 0;
                }
            }
        int ans = 0;
        for (int i=0, t=(1<<n)-1; i<n; ++i)
            ans += f(t, i, A, tb);
        unordered_map<int, int> cnt;
        for (int i=0; i<n; ++i) ++cnt[A[i]];
        for (auto &[_, c] : cnt)
            for (int k=c; k > 1; --k)
                ans /= k;
        return ans;
    }
};