// Two Pointers, Binary Search, Greedy, Sliding Window

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int p = 0, q = n, s = 0, ans = n+1;
        while (q > 0 && s < x) s += nums[--q];
        if (s < x) return -1;
        if (s == x) ans = p + (n - q);
        while (q < n) {
            s += nums[p++];
            while (q < n && s > x) s -= nums[q++];
            if (s == x) ans = min(ans, p + (n - q));
        }
        return ans == n+1 ? -1 : ans;
    }
};