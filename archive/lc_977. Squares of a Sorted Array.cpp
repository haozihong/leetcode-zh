// Array, Two Pointers

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> tmp;
        auto it1 = begin(nums);
        while (it1 != end(nums) && *it1 < 0)
            tmp.push_back(-*it1++);
        auto it2 = rbegin(tmp);
        auto it = begin(nums);
        while (it2 != rend(tmp) && it1 != end(nums))
            *it++ = *it2 < *it1 ? *it2++ : *it1++;
        while (it2 != rend(tmp))
            *it++ = *it2++;
        for_each(begin(nums), end(nums), [](int &x) { x *= x; });
        return nums;
    }
};