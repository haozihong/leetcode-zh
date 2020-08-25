// DP

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size());
        dp[0] = min({costs[0], costs[1], costs[2]});
        for (int i=1, l=days.size(), j1=0, j2=0, t1, t2; i<l; ++i) {
            while (days[j1] + 7 <= days[i]) ++j1;
            t1 = (j1 ? dp[j1-1] : 0) + costs[1];
            
            while (days[j2] + 30 <= days[i]) ++j2;
            t2 = (j2 ? dp[j2-1] : 0) + costs[2];
            
            dp[i] = min({dp[i-1] + costs[0], t1, t2});
        }
        return dp.back();
    }
};