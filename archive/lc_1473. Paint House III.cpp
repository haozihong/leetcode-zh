// DP

class Solution {
public:
    int f(int i, int j, int k, vector<vector<vector<int>>> &dp, vector<int>& houses, vector<vector<int>>& cost) {
        if (k < 0) return -1;
        if (dp[i][j][k] != -2) return dp[i][j][k];
        if (houses[i] != 0 && houses[i]-1 != j) return dp[i][j][k] = -1;
        if (i == 0) return dp[i][j][k] = k == 0 ? (houses[i] == 0 ? cost[i][j] : 0) : -1;
        if (houses[i-1] != 0) {
            dp[i][j][k] = f(i-1, houses[i-1]-1, k - (houses[i-1]-1 != j), dp, houses, cost);
        } else {
            dp[i][j][k] = -1;
            for (int jj=0, m=cost[0].size(), t; jj<m; ++jj) {
                t = f(i-1, jj, k - (jj != j), dp, houses, cost);
                if (t != -1 &&(dp[i][j][k] == -1 || t < dp[i][j][k])) dp[i][j][k] = t;
            }
        }
        return dp[i][j][k] != -1 && houses[i] == 0 ? dp[i][j][k] += cost[i][j] : dp[i][j][k];
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, -2)));
        if (houses[m-1] != 0) {
            return f(m-1, houses[m-1]-1, target-1, dp, houses, cost);
        } else {
            int mn = -1;
            for (int j=0, t; j<n; ++j) {
                t = f(m-1, j, target-1, dp, houses, cost);
                if (t != -1 && (mn == -1 || t < mn)) mn = t;
            }
            return mn;
        }
    }
};