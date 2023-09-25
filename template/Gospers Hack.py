class Solution:
    def getMaxGridHappiness(self, m: int, n: int, inCount: int, exCount: int) -> int:
        def gh(m, k):
            '''Gospers Hack'''
            mask = (1<<k) - 1
            while mask < 1<<m:
                yield mask
                c = mask & -mask
                r = mask + c
                mask = (((r ^ mask) >> 2) // c) | r
        states = {(0,)}
        for k in range(2, 1 + min(m * n, inCount + exCount)):
            for s in gh(m*n, k):
                state = []
                for c, r in product(range(m), range(n)):
                    if s & 1<<(c*n+r):
                        state.append(
                            sum(0<=c2<m and 0<=r2<n and bool(s&1<<(c2*n+r2))
                                for c2, r2 in ((c-1,r),(c+1,r),(c,r-1),(c,r+1)))
                        )
                states.add(tuple(sorted(state)))
        print(states)