class Solution:
    def longestDupSubstring(self, S: str) -> str:
        lng = len(S)
        A = [ord(c) - 97 for c in S]
        M, MOD = 26, (1<<63)-1
        def search(l):
            if l == 0: return None
            ha = functools.reduce(lambda x, y: (x*M + y)% MOD, A[:l])
            ss = {ha}
            t = pow(M, l-1, MOD)
            for i in range(1, lng-l+1):
                ha = ((ha - A[i-1]*t)*M + A[i+l-1])% MOD
                if ha in ss: return i
                ss.add(ha)
        res, l, r = 0, 0, lng
        while l + 1 < r:
            m = (l + r) // 2
            p = search(m)
            if p: l, res = m, p
            else: r = m
        return S[res:res+l]