// Greedy, Graph, 

// 2020-08-12:
// 发现不成对的，就改成正确的数字，然后为被改掉的数字找它应在的位置。
// 如此必会循环到开始改数字的最初位置。若此环长为 l，则需要 l-1 次换座。

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int l = row.size();
        vector<int> d(l);
        for (int i=0; i<l; ++i) d[row[i]] = i;
        int ans = 0;
        for (int i=0; i<l; i += 2) {
            if (row[i^1] == (row[i] ^ 1)) continue;
            int j = i;
            do {
                ++ans;
                int t = row[j^1];
                row[j^1] = row[j] ^ 1;
                j = d[t^1];
            } while (j != i);
            --ans;
        }
        return ans;
    }
};