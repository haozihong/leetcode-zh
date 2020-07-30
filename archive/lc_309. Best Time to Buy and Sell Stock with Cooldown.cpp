class Solution {
public:
    int maxProfit(vector<int>& A) {
        int sold = INT_MIN, held = INT_MIN, cd_sold = 0;
        for (auto &p : A) {
            int sold0 = sold;
            sold = held + p;
            held = max(held, cd_sold - p);
            cd_sold = max(cd_sold, sold0);
        }
        return max(cd_sold, sold);
    }
};