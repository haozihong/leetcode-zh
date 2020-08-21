// Math, Hash Table, Tricky, O(1) space

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            auto &p = nums[i];
            while (1 <= p && p <= n && nums[p-1] != p) swap(nums[p-1], p);
        }
        for (int i=0; i<n; ++i)
            if (nums[i] != i + 1)
                return {nums[i], i + 1};
        return {};
    }
};