// Dynamic Programming, DP

class Solution {
public:
    int lastStoneWeightII(vector<int>& A) {
        int n = A.size();
        vector<bool> dp(n*100+1, false);
        dp[0] = true;
        int mx = 0;
        for (auto &w : A) {
            vector<bool> dp2(n*100+1, false);
            for (int i=mx; i>=0; --i)
                if (dp[i]) dp2[i+w] = dp2[abs(i-w)] = true, mx = max(mx, i+w);
            dp.swap(dp2);
        }
        for (int i=0; i<=mx; ++i) if (dp[i]) return i;
        return 0;
    }
};