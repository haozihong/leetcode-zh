// Backtracking

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& A) {
        int n = A.size();
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        while (1) {
            ans.push_back(A);
            auto p = rbegin(A) + 1;
            while (p != rend(A) && *p >= *(p-1)) ++p;
            if (p == rend(A)) break;
            auto q = upper_bound(rbegin(A), p, *p);
            swap(*p, *q);
            reverse(rbegin(A), p);
        }
        return ans;
    }
};