// Array, Binary Search

class Solution {
public:
    static constexpr double TOL = 1e-5;
    
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sk = accumulate(begin(nums), begin(nums) + k, 0);
        auto pmnmx = minmax_element(begin(nums), end(nums));
        double l = *pmnmx.first, r = *pmnmx.second;
        while (r - l > TOL) {
            double m = (l + r) / 2;
            double s = sk - k * m, x = 0, mnx = 0;
            for (int i=k; i<n && s-mnx<0; ++i) {
                s += nums[i] - m;
                x += nums[i-k] - m;
                mnx = min(mnx, x);
            }
            if (s - mnx < 0) r = m;
            else l = m;
        }
        return l;
    }
};