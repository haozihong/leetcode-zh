// Array

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        nums.push_back(upper+1);
        int pre = lower-1;
        vector<string> ans;
        for (auto &x : nums) {
            if (x > pre + 1) {
                int a = pre + 1, b = x - 1;
                ans.push_back(a==b? to_string(a) : to_string(a) + "->" + to_string(b));
            }
            pre = x;
        }
        return ans;
    }
};