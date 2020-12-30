// Hash Table, Two Pointers, String, Sliding Window

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        if (k == 0) return 0;
        array<int, 128> cnt;
        fill(begin(cnt), end(cnt), 0);
        int char_num = 0;
        int mx = 0;
        for (int i=0, j=0, n=s.length(); i<n && j<n; ++i) {
            while (j<n && (char_num < k || cnt[s[j]] > 0))
                if (++cnt[s[j++]] == 1) ++char_num;
            mx = max(mx, j - i);
            if (--cnt[s[i]] == 0) --char_num;
        }
        return mx;
    }
};