// Math

class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        // # of candies person i should get in round k
        static auto f = [&n](int i, int k) { return i+1 + k*n; };
        // # of candies person i should hold after round k
        static auto ff = [&n](int i, int k) { return (i+1 + i+1 + k*n) * (k+1) / 2; };
        // # of candies needed for round k
        static auto g = [&n](int k) { return n * (n+1) / 2 + k * n * n; };
        int k = 0;
        for (int t = g(k); t <= candies; t = g(++k))
            candies -= t;
        vector<int> ans(n);
        for (int i=0, t=f(i, k); i<n; t=f(++i, k)) {
            if (t <= candies) {
                candies -= t;
                ans[i] = ff(i, k-1) + t;
            } else {
                ans[i] = ff(i, k-1) + candies;
                candies = 0;
            }
        }
        return ans;
    }
};