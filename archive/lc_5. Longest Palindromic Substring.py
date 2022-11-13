# String, Dynamic Programming (dp)
# Manacher's Algorithm

class Solution:
    def longestPalindrome(self, s: str) -> str:
        s2 = '#' + '#'.join(s) + '#'
        ln2 = len(s2)
        d = [1] * ln2
        pre = 0
        for i in range(1, ln2 - 1):
            if pre + d[pre] > i:
                d[i] = min(pre + d[pre] - i, d[pre-(i-pre)])
            while 0 <= i-d[i] and i+d[i] < ln2 and s2[i-d[i]] == s2[i+d[i]]:
                d[i] += 1
            if i + d[i] > pre + d[pre]: pre = i
        d = [x-1 for x in d]
        mxi = max(range(ln2), key=d.__getitem__)
        return s[(mxi-d[mxi])//2:(mxi+d[mxi])//2]