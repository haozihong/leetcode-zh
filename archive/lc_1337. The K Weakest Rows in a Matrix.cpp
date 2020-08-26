// Array, Binary Search

class Solution1 {  // 20ms. faster
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int, int>> s;
        for (int i=0, l=mat.size(); i<l; ++i)
            s.emplace(upper_bound(begin(mat[i]), end(mat[i]), 1, greater<int>()) - begin(mat[i]), i);
        vector<int> ans;
        generate_n(back_inserter(ans), k, [it=begin(s)]() mutable { return (it++)->second; });
        return ans;
    }
};

class Solution {  // 52ms
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> pows;
        for (int i=0, l=mat.size(); i<l; ++i)
            pows.emplace_back(upper_bound(begin(mat[i]), end(mat[i]), 1, greater<int>()) - begin(mat[i]), i);
        priority_queue s(greater<pair<int, int>>(), move(pows));
        vector<int> ans;
        while (k--) {
            ans.push_back(s.top().second);
            s.pop();
        }
        return ans;
    }
};