// Array, tricky

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto &x : nums)
            if (nums[abs(x)-1] > 0) nums[abs(x)-1] *= -1;
        vector<int> ans;
        for (int i=0, l=nums.size(); i<l; ++i) 
            if (nums[i] > 0) ans.push_back(i+1);
        return ans;
    }
};