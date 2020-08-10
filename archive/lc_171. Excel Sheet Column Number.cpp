// Math, Base

class Solution {
public:
    int titleToNumber(string s) {
        int t = 0;
        for (auto &c : s)
            t = t * 26 + (c - 64);
        return t;
    }
};