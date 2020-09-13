// Array, Sort, Interval, Hard, Complex

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& newInterval) {
        if (A.empty()) return {newInterval};
        
        int il = newInterval[0], ir = newInterval[1];
        auto it1 = lower_bound(begin(A), end(A), il, [](vector<int> x, int y) { return x[1] < y; });
        auto it2 = upper_bound(begin(A), end(A), ir, [](int x, vector<int> y) { return x < y[0]; }) - 1;
        if (it2 < it1) {
            A.insert(it1, newInterval);
            return A;
        }
        
        (*it1)[0] = min((*it1)[0], il);
        (*it1)[1] = max((*it2)[1], ir);
        A.erase(it1 + 1, it2 + 1);
        return A;
    }
};