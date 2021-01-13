// Binary Search

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = *max_element(begin(piles), end(piles));
        while (l < r) {
            int m = l + (r - l) / 2, t = 0;
            for (auto &x : piles) {
                t += x / m + (x % m != 0);
                if (t > H) break;
            }
            if (t <= H) r = m;
            else l = m + 1;
        }
        return l;
    }
};