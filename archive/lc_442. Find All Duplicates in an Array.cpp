// Array, tricky

class Solution1 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        // nums[i] marked as 0: nums[i] has been counted; -1: i has been counted once
        for (int i=0, l=nums.size(); i<l; ++i) {
            if (nums[i] <= 0) continue;
            int j = nums[i] - 1;
            nums[i] = 0;
            while (j >= 0 && nums[j] >= 0) {
                int j2 = nums[j] - 1;
                nums[j] = -1;
                j = j2;
            }
            if (j >= 0 && nums[j] == -1) ans.push_back(j+1);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (auto &x : nums) {
            if (nums[abs(x)-1] < 0)  // seen before
                ans.push_back(abs(x));
            nums[abs(x)-1] *= -1;
        }
        return ans;
    }
};