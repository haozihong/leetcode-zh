// Array, DP, Dynamic Programming, Greedy

class Solution {
public:
    int maxProfit(vector<int>& A) {
        int held1 = INT_MIN, held2 = INT_MIN, sold1 = 0, sold2 = 0;
        for(auto &p : A) {
            sold2 = max(sold2, held2 + p);
            held2 = max(held2, sold1 - p);
            sold1 = max(sold1, held1 + p);
            held1 = max(held1, -p);
        }
        return sold2;
    }
};