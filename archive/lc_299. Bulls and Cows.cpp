// Hash Table

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> cnt;
        for (auto &c : secret) ++cnt[c];
        for (auto &c : guess) if (cnt[c]) --cnt[c];
        int a = 0, ab = secret.length();
        for (auto [c, n] : cnt) ab -= n;
        for (int i=0, l=secret.length(); i<l; ++i)
            if (secret[i] == guess[i]) ++a;
        return to_string(a) + "A" + to_string(ab-a) + "B";
    }
};