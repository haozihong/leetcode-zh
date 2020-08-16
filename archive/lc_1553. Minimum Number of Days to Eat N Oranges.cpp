// DP, Dynamic Programming, BFS
// DP本质是DFS，如果察觉到DFS会对非最优解的分支深入很多层，则可改成BFS
// 本题从n往1进行BFS，比从1到n减少很多分支，因为无法被2、3整除的都去掉了。

class Solution {
public:
    int minDays(int n) {
        unordered_set<int> s{n};
        for (int step=1; 1; ++step) {
            if (s.count(1) == 1) return step;
            unordered_set<int> nxt;
            for (auto &x : s) {
                nxt.insert(x-1);
                if (x%2==0) nxt.insert(x/2);
                if (x%3==0) nxt.insert(x/3);
            }
            s.swap(nxt);
        }
        return -1;
    }
};

class Solution2 {
    unordered_map<int, int> dp;
    int minDays(int n) {
        if (n <= 1) return n;
        if (dp.count(n) == 0)
            dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
        return dp[n];
    }
}