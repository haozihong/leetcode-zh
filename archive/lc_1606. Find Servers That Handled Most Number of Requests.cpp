// Heap and Balance Search Tree, almost TLE. Should be some better way

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& tt, vector<int>& tl) {
        priority_queue<
            pair<int, int>,
            deque<pair<int, int>>,
            greater<pair<int, int>>> que;  // ava_time, server id
        set<int> free;
        for (int i=0; i<k;++i) free.insert(i);
        vector<int> cnt(k, 0);
        int mxl = 0;
        for (int i=0, n=tt.size(), t, l; i<n; ++i) {
            t = tt[i]; l = tl[i];
            while (!que.empty() && que.top().first <= t) {
                free.insert(que.top().second);
                que.pop();
            }
            auto it = free.lower_bound(i % k);
            if (it == free.end()) it = free.begin();
            if (it != free.end()) {
                que.emplace(t + l, *it);
                mxl = max(mxl, ++cnt[*it]);
                free.erase(it);
            }
        }
        vector<int> ans;
        for (int i=0; i<k; ++i)
            if (cnt[i] == mxl) ans.push_back(i);
        return ans;
    }
};