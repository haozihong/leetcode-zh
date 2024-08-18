# Segment Tree

class SegTreeNode:  # [l, r)
    def __init__(self, l, r, data):
        self.l, self.r, self.data, self.lazy = l, r, data, 0
        self.m = (l + r) // 2
        if r - l <= 1:
            self.v = data[l]
        else:
            self.c = SegTreeNode(l, self.m, data), SegTreeNode(self.m, r, data)
            self.v = self.c[0].v + self.c[1].v
    
    def push(self):
        if self.r - self.l > 1 and self.lazy != 0:
            for c in self.c:
                c.lazy += self.lazy
                c.v += (c.r - c.l) * self.lazy
            self.lazy = 0
    
    def add(self, l, r, val):
        if l <= self.l and self.r <= r:
            nl, data = self.l, self.data
            self.lazy += val
            self.v += (self.r - self.l) * val
            return
        self.push()
        if l < self.m: self.c[0].add(l, r, val)
        if self.m < r: self.c[1].add(l, r, val)
        self.v = self.c[0].v + self.c[1].v

    def query(self, l, r):
        if l <= self.l and self.r <= r: return self.v
        self.push()
        res = 0
        if l < self.m: res += self.c[0].query(l, r)
        if self.m < r: res += self.c[1].query(l, r)
        return res

class Solution:
    def countKConstraintSubstrings(self, s: str, k: int, queries: List[List[int]]) -> List[int]:
        n = len(s)
        nxt = [0] * n
        q, cnt = 0, Counter()
        for p in range(n):
            while q < n and (cnt['0'] <= k or cnt['1'] <= k):
                cnt[s[q]] += 1
                q += 1
            nxt[p] = q - (cnt['0'] > k and cnt['1'] > k)
            cnt[s[p]] -= 1
        res = [0] * len(queries)
        seg = SegTreeNode(0, n, [0] * n)
        p = n - 1
        for idx, (l, r) in sorted(enumerate(queries), key=lambda x: -x[1][0]):
            while p >= l:
                seg.add(p, nxt[p], 1)
                p -= 1
            res[idx] = seg.query(l, r+1)
        return res