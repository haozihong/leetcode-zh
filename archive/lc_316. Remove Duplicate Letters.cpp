// String, Stack, Greedy

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, deque<int>> mp;  // indexes of char c
        vector<int> ss(s.length(), 0);  // bit state from i to s.end()
        int todo = 0;
        for (int i=s.length(); i--;) {
            mp[s[i]].push_front(i);
            ss[i] = todo |= 1<<(s[i] - 'a');
        }
        string ans = "";
        int st = 0;
        while (todo)
            for (char c='a'; c<='z'; ++c)
                if (todo & 1<<(c-'a')) {
                    while (!mp[c].empty() && mp[c][0] < st) mp[c].pop_front();
                    for (auto &i : mp[c])
                        if ((ss[i] & todo) == todo) {
                            ans += c;
                            st = i;
                            todo -= 1<<(c - 'a');
                            break;
                        }
                    if (ans.back() == c) break;
                }
        return ans;
    }
};