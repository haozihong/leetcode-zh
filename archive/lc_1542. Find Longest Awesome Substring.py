# Bit Manipulation

class Solution:
    def longestAwesome(self, s: str) -> int:
        a = [0]
        for c in s:
            a.append(a[-1] ^ (1<<int(c)))
        d = {}
        mx = 0
        for i, x in enumerate(a):
            tmp = d[x] if x in d else i
            for j in range(10):
                t = x ^ 1<<j
                if t in d: tmp = min(tmp, d[t])
            mx = max(mx, i - tmp)
            if x not in d: d[x] = i
        return mx