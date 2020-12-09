// Array

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60, 0);
        int ans = 0;
        for (auto &x : time)
            ans += cnt[(60-x%60)%60], ++cnt[x%60];
        return ans;
    }
};