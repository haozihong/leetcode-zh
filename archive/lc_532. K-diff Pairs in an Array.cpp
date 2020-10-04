// Array, Hash Table, Two Pointers?

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        if (k == 0) {
            unordered_map<int, int> mp;
            for(auto &x : nums) {
                if (mp[x] == 1) ++ans;
                ++mp[x];
            }
        } else {
            unordered_set<int> s(begin(nums), end(nums));
            for (auto &x : s)
                if (s.count(x + k)) ++ans;
        }
        return ans;
    }
};