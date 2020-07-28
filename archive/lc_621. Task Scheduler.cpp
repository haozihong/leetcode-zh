class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        for (auto& c : tasks) ++cnt[c-65];
        int mx = *max_element(cnt.begin(), cnt.end());
        int mxn = count(cnt.begin(), cnt.end(), mx);        
        return max((int) tasks.size(), mxn + (n+1)*(mx-1));
    }
};