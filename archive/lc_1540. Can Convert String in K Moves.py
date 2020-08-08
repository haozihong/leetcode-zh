# String, Greedy

class Solution:
    def canConvertString(self, s: str, t: str, k: int) -> bool:
        if len(s) != len(t): return False
        dic = {i: (k-i)//26+1 for i in range(26)}
        for c1, c2 in zip(s, t):
            d = (ord(c2) - ord(c1) + 26) % 26
            if d == 0: continue
            if dic[d] <= 0: return False
            dic[d] -= 1
        return True