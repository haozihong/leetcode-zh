// Bit Manipulation, Trie, Hash map

class Solution1 {  // Trie
public:
    const int K = 31;
    
    void add_num(vector<array<int, 2>> &trie, int x) {
        int p = 0;
        for (int k=K; k--;) {
            bool t = (x >> k) & 1;
            if (trie[p][t] == 0) {
                trie[p][t] = trie.size();
                trie.push_back({0, 0});
            }
            p = trie[p][t];
        }
    }
    
    int max_xor(vector<array<int, 2>> &trie, int x) {
        int p = 0, res = 0;
        for (int k=K; k--;) {
            bool t = (x >> k) & 1;
            if (trie[p][!t] != 0) {
                res += 1 << k;
                p = trie[p][!t];
            } else {
                p = trie[p][t];
            }
        }
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        vector<array<int, 2>> trie(1, {0, 0});
        for (auto &x : nums) add_num(trie, x);
        int mx = 0;
        for (auto &x : nums) mx = max(mx, max_xor(trie, x));
        return mx;
    }
};

class Solution {  // Hash map
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0, mx = *max_element(begin(nums), end(nums));
        if (mx == 0) return 0;
        unordered_set<int> ss;
        for (int k=32-__builtin_clz(mx); k--;) {
            ss.clear();
            for (auto &x : nums) ss.insert(x >> k);
            ans <<= 1;
            for (auto &pre : ss)
                if (ss.count(pre ^ (ans+1))) {
                    ++ans;
                    break;
                }
        }
        return ans;
    }
};