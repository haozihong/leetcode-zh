// Array, DP

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto bg = begin(nums);
        int pre0 = -1, neg_cnt = 0, neg1, neg2, mx = *max_element(bg, end(nums));
        for (int i=0, l=nums.size(); i<l; ++i) {
            if(nums[i] == 0) {
                pre0 = i;
            } else {
                if (nums[i] < 0) {
                    if (neg_cnt == 0) neg1 = i;
                    neg2 = i;
                    ++neg_cnt;
                }
                if (i == l - 1 || nums[i+1] == 0) {
                    if (neg_cnt % 2 == 0) {
                        mx = max(mx, accumulate(bg+pre0+1, bg+i+1, 1, multiplies<int>()));
                    } else {
                        if (pre0 + 1 != neg2)
                            mx = max(mx, accumulate(bg+pre0+1, bg+neg2, 1, multiplies<int>()));
                        if (neg1 != i)
                            mx = max(mx, accumulate(bg+neg1+1, bg+i+1, 1, multiplies<int>()));
                    }
                    neg_cnt = 0;
                }
            }
        }
        return mx;
    }
};