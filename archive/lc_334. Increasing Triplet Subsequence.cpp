//

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn1 = INT_MAX, mn2 = INT_MAX;
        for (auto &x : nums) {
            if (x > mn2) return true;
            if (x > mn1 && x < mn2) mn2 = x;
            if (x < mn1) mn1 = x;
        }
        return false;
    }
};