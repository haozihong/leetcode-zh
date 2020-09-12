// Array, DP, Divide and Conquer, Kadane's Algorithm

class Solution1 {  // Kadane's algorithm
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        long long int t = 0, mn = 0;
        for (auto &x : nums) {
            t += x;
            if (t - mn > ans) ans = t - mn;
            mn = min(mn, t);
        }
        return ans;
    }
};

class Solution {  // Divide and Conquer
public:
    template<typename RandomIt>
    tuple<int, int, int> subq(RandomIt first, RandomIt last, char side) {  // 1:left; 2:right; 3:both
        if (first + 1 == last) return {*first, *first, *first};
        auto mid = first + (last - first) / 2;
        auto [t1m, t1l, t1r] = subq(first, mid, side & 1 ? 3 : 2);
        auto [t2m, t2l, t2r] = subq(mid, last, side & 2 ? 3 : 1);
        int res1 = max({t1m, t2m, t1r + t2l}), res2, res3;
        if (side & 1) {  // left
            auto sm1 = accumulate(first, mid, 0);
            res2 = max(t1l, sm1 + t2l);
        }
        if (side & 2) {  // right
            auto sm2 = accumulate(mid, last, 0);
            res3 = max(t2r, sm2 + t1r);
        }
        return {res1, res2, res3};
    }
    
    int maxSubArray(vector<int>& nums) {
        return get<0>(subq(begin(nums), end(nums), 0));
    }
};