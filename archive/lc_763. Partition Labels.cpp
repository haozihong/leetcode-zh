// Greedy, Two Pointers

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> last;
        for (int i=0, n=S.length(); i<n; ++i)
            last[S[i]] = i;
        vector<int> ans;
        for (int i=0, l, r, n=S.length(); i<n; ){
            l = i; r = last[S[i]];
            for (++i; i<=r; ++i) r = max(r, last[S[i]]);
            ans.push_back(r - l + 1);
        }
        return ans;
    }
};